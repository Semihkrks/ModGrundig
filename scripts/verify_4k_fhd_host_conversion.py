"""Host-only reproducible conversion experiment, never TV firmware execution.

Generates a short SDR HEVC Main10 4K + AC-3 fixture and converts to 1080p25
AVC + AAC-LC. This cannot establish native satellite decoding on the TV.
"""
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / 'analiz/native-4k/host-conversion'


def run(args):
    return subprocess.run(args, check=True, capture_output=True, text=True,
                          encoding='utf-8', errors='replace', timeout=120)


def probe(path):
    return json.loads(run([shutil.which('ffprobe'), '-v', 'error',
                           '-show_streams', '-of', 'json', str(path)]).stdout)['streams']


def main():
    if not shutil.which('ffmpeg') or not shutil.which('ffprobe'):
        raise RuntimeError('Host FFmpeg and ffprobe required; no auto-install')
    if OUT.exists():
        raise FileExistsError('Retained experiment exists; refusing overwrite')
    OUT.mkdir(parents=True)
    source, target = OUT/'synthetic-main10-ac3.mkv', OUT/'fhd-avc-aac.mp4'
    ff = shutil.which('ffmpeg')
    common = [ff, '-hide_banner', '-loglevel', 'error', '-nostdin', '-n']
    generate = common + ['-f', 'lavfi', '-i', 'testsrc2=size=3840x2160:rate=50',
        '-f', 'lavfi', '-i', 'sine=frequency=1000:sample_rate=48000',
        '-t', '0.4', '-c:v', 'libx265', '-preset', 'ultrafast',
        '-x265-params', 'pools=2:frame-threads=2:log-level=error',
        '-pix_fmt', 'yuv420p10le', '-color_primaries', 'bt709',
        '-color_trc', 'bt709', '-colorspace', 'bt709',
        '-c:a', 'ac3', '-b:a', '192k', str(source)]
    run(generate)
    convert = common + ['-i', str(source), '-map', '0:v:0', '-map', '0:a:0',
        '-vf', 'scale=1920:1080:flags=lanczos,fps=25,setsar=1',
        '-c:v', 'libx264', '-threads', '2', '-preset', 'fast',
        '-profile:v', 'main', '-level:v', '4.0', '-pix_fmt', 'yuv420p',
        '-crf', '20', '-maxrate', '8M', '-bufsize', '16M',
        '-c:a', 'aac', '-profile:a', 'aac_low', '-ac', '2', '-ar', '48000',
        '-b:a', '192k', '-movflags', '+faststart', str(target)]
    run(convert)
    before, after = probe(source), probe(target)
    video = next(s for s in before if s['codec_type'] == 'video')
    audio = next(s for s in before if s['codec_type'] == 'audio')
    vout = next(s for s in after if s['codec_type'] == 'video')
    aout = next(s for s in after if s['codec_type'] == 'audio')
    assert (video['codec_name'], video['profile'], video['width'], video['height']) == ('hevc', 'Main 10', 3840, 2160)
    assert audio['codec_name'] == 'ac3'
    assert (vout['codec_name'], vout['width'], vout['height'], vout['pix_fmt']) == ('h264', 1920, 1080, 'yuv420p')
    assert (aout['codec_name'], aout['profile'], aout['channels']) == ('aac', 'LC', 2)
    decoded = run([ff, '-v', 'error', '-xerror', '-nostdin', '-i', str(target), '-f', 'null', '-'])
    loudness = run([ff, '-hide_banner', '-nostdin', '-i', str(target), '-vn',
                    '-af', 'volumedetect', '-f', 'null', '-']).stderr
    assert 'mean_volume:' in loudness and 'mean_volume: -inf' not in loudness
    report = dict(status='PASS_HOST_ONLY', television_tested=False,
        native_firmware_changed=False, live_satellite_conversion=False,
        synthetic_input=True, hdr_tested=False, realtime_performance_measured=False,
        output_frame_rate='25fps; this deliberately reduces the 50fps input',
        ffmpeg_version=run([ff, '-version']).stdout.splitlines()[0],
        generate_command=generate, convert_command=convert,
        input_streams=before, output_streams=after,
        output_decode_errors=decoded.stderr, output_audio_non_silent=True,
        files={p.name:dict(bytes=p.stat().st_size, sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in (source,target)},
        source='https://ffmpeg.org/ffmpeg.html',
        limitations='Short synthetic SDR clip only; no RF/PMT, HDR, long-run, HE-AAC or TV compatibility proof')
    (OUT/'results.json').write_text(json.dumps(report, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({k:report[k] for k in ('status','television_tested','output_audio_non_silent')}))


if __name__ == '__main__':
    main()
