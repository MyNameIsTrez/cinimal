# Fixing NODE_MODULE_VERSION errors

I had been stumped on this error for a while:
> Activating extension failed: The module was compiled against a different Node.js version using NODE_MODULE_VERSION 111. This version of Node.js requires NODE_MODULE_VERSION 110.

The ABI of Node.js for me was different from the one used by Electron, Electron being module version 110 and Node.js 111, as seen [here](https://github.com/nodejs/node/commit/3efe901dd6).

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

# Fixing `npm install tree-sitter` errors

`nvm install 18.16.0`
`nvm use 18.16.0`
`./node_modules/.bin/electron-rebuild`

https://github.com/electron/rebuild/issues/1031#issuecomment-1241690118

Manually replacing incrementing `package-lock.json` its `"node-abi": "^3.0.0",` to `"node-abi": "^3.24.0",` didn't help

Adding this to `package.json` didn't help:
```
"overrides": {
  "electron-rebuild": {
    "node-abi": "3.24.0"
  }
}
```
