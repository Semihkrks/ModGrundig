param(
    [ValidateSet('original', 'v2', 'v3')]
    [string]$Variant = 'v2',
    [ValidateSet('none', 'ubi-directory', 'ubi-mpool-name', 'ubi-mpool-empty')]
    [string]$Topology = 'none'
)
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$LabScript = Join-Path (Split-Path $PSScriptRoot -Parent) 'scripts/emulation_lab.py'
$PosixStylePath = $LabScript.Replace('\', '/')
$ConvertedPath = & wsl -d Ubuntu -u semih --exec /usr/bin/wslpath -u $PosixStylePath
if ($LASTEXITCODE -ne 0 -or -not $ConvertedPath) { throw 'WSL path conversion failed.' }
$LinuxLabScript = $ConvertedPath.Trim()
Write-Host 'Grundig MIPS application laboratory: no complete TV emulation or visual screen.'
Write-Host 'Only the pinned application runs inside a read-only, offline namespace.'
& wsl -d Ubuntu -u semih --exec /usr/bin/python3 $LinuxLabScript fixtures --variant $Variant
if ($LASTEXITCODE -ne 0) { throw 'Synthetic fixture validation failed; target was not launched.' }
$RunArguments = @('run', '--variant', $Variant)
if ($Topology -ne 'none') { $RunArguments += @('--topology', $Topology) }
& wsl -d Ubuntu -u semih --exec /usr/bin/python3 $LinuxLabScript @RunArguments
if ($LASTEXITCODE -ne 0) { throw 'Laboratory setup/isolation failed.' }
$ReportSuffix = if ($Topology -eq 'none') { '' } else { "-$Topology" }
Write-Host "Result: analiz/emulation-lab/run-$Variant$ReportSuffix.json (inspect exit_code; 0 from this wrapper is not TV compatibility)."
