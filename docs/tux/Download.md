# Downloading cavg

Start by opening a terminal.

Enter the command:

```bash
git clone https://github.com/hangarau/cavg/cavg.git && cd cavg
```
If you don't have git installed, install it with:

```bash
sudo apt install git
```

If you're building, you're done. All the files are in the `cavg` directory you got dropped into.
If you're downloading for usage, you'll want to run the setup file.

Make the file executable with:
```bash
sudo chmod +x setup/lSetup.sh
```
And run it with:
```bash
sudo ./setup/lSetup.sh
```

After that, the "_cavg_" command will be installed and ready to use.