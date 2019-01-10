@echo off
vc_redist.x86.exe
mkdir "C:\Program Files (x86)\Redwood Hotel Casino\Unlock The Box Promotion Manager\Installer"
mkdir "C:\Program Files (x86)\Redwood Hotel Casino\Unlock The Box Promotion Manager\Resource Files"
copy UnlockTheBoxInstaller.msi "C:\Program Files (x86)\Redwood Hotel Casino\Unlock The Box Promotion Manager\Installer"
copy setup.exe "C:\Program Files (x86)\Redwood Hotel Casino\Unlock The Box Promotion Manager\Installer"
setup.exe