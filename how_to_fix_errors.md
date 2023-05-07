# How to fix errors

I had been stumped on this error for a while:
> Activating extension failed: The module was compiled against a different Node.js version using NODE_MODULE_VERSION 111. This version of Node.js requires NODE_MODULE_VERSION 110.

The ABI of Node.js for me was different from the one used by Electron, Electron being module version 110 and Node.js 111.

I used electron-rebuild, detailed below, to make the ABIs compatible, but it looks for `node_modules/.bin/electron`, which I didn't have.

I needed to make sure I put the same Electron version there as VS Code uses, so find the electron version your VS Code in VS Code's `package.json`.
Mine is located at
`C:\Users\welfj\AppData\Local\Programs\Microsoft VS Code\resources\app\package.json`
and contains `"electron": "22.3.5",`, so:
`npm install electron@22.3.5`

See [this Stack Overflow answer](https://stackoverflow.com/a/67309198/13279557) for more details on these commands:
`npm install --save-dev electron-rebuild`
`./node_modules/.bin/electron-rebuild`

This got rid of the error.
