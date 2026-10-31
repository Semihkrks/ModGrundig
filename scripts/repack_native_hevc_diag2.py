"""Apply the same fixed-slot repacker to an isolated second-stage release."""
import repack_native_hevc_diag as repack

if __name__ == '__main__':
    repack.OUT = repack.ROOT/'analiz/native-ui-candidate/v7.9-hevc-diag2/package'
    repack.FILENAME = 'GM_SWImage_UI_v7.9-hevc-diag2_OFFLINE_UNVERIFIED.bin'
    repack.main()
