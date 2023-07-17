# Downloading cavg

Start by opening the Command Prompt or PowerShell on Windows.

Enter the command:

```batch
git clone https://github.com/hangarau/cavg/cavg.git && cd cavg
```
If you don't have Git installed, you can download and install it from the [official website](https://git-scm.com/download/win).

If you're building, you're done. All the files are now in the cavg directory you navigated to.
If you're downloading for usage, you'll want to run the appropriate setup file.

There are two available setup files, `Setup32` and `Setup64` for 32-bit and 64-bit respectively.
You can run these files with:

```batch
setup\SetupXX.bat
```
Replace `XX` with either 32 or 64 depending on your CPU architecture.

After that, the "cavg" command will be installed and ready to use.