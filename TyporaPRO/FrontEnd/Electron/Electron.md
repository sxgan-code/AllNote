# 一、简介

## 1、Electron是什么？

+ [官网](https://www.electronjs.org/)
+ Electron是一个使用 JavaScript、HTML 和 CSS 构建桌面应用程序的框架。 嵌入 [Chromium](https://www.chromium.org/) 和 [Node.js](https://nodejs.org/) 到 二进制的 Electron 允许您保持一个 JavaScript 代码代码库并创建 在Windows上运行的跨平台应用 macOS和Linux——不需要本地开发 经验。

## 2、基本要求

熟悉该文档之前，需要你有`Node.js`和`web`开发经验。 如果您需要了解这两个方面的开发知识，我们推荐您使用以下学习资源：

- [来自Mozilla开发社区(Mozilla Developer Network)的web入门教程](https://developer.mozilla.org/en-US/docs/Learn/Getting_started_with_the_web)
- [NodeJS官方入门指南](https://nodejs.dev/learn)

此外，如果您熟悉Chromium进程模型，您将更好了解 Electron 的工作原理。 您可以通过阅读[Chrome comic](https://www.google.com/googlebooks/chrome/)来获得Chrome架构的简要概述，Chrome架构于2008年同Chrome浏览器的发布而发行。 尽管Chrome发布十多年了，【Chrome comic】漫画中介绍的核心原理仍然有助于理解Electron。

# 二、快速搭建

## 1、安装electron

初始化`package.json`文件

```sh
npm init
```

安装electron

```sh
npm i electron –S
```

## 2、配置为入口文件

```js
{
  "name": "bcelectronlearn",
  "version": "1.0.0",
  "description": "learn electron",
  "main": "main.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "author": "Daniel",
  "license": "ISC",
  "dependencies": {
    "electron": "^19.0.9"
  }
}

```

## 3、创建main.js文件

```js
const electron = require('electron')
// 控制应用程序的事件生命周期。
const app = electron.app 
// 当 Electron 完成初始化时，触发一次
app.on('ready', ()=>{
  new electron.BrowserWindow({
    width: 800,
    height: 800
  })
})
```

## 4、创建窗口

```js
app.on('ready', () => {
    const mainWindow = new electron.BrowserWindow({
        width: 800,
        height: 800
    })
    // 加载页面
    mainWindow.loadFile('./src/index.html')
})
```

# 四、自动刷新页面

## 1、安装插件

```sh
npm install --save-dev electron-reloader
```

## 2、在入口main.js引入插件

```js
const reloader = require('electron-reloader')
reloader(module)
```

# 五、主进程和渲染进程

## 1、什么主进程和渲染进程

Electron 运行 `package.json` 的 `main` 脚本的进程被称为**主进程**。 在主进程中运行的脚本通过创建web页面来展示用户界面。 一个 Electron 应用总是有且只有一个主进程。

由于 Electron 使用了 Chromium 来展示 web 页面，所以 Chromium 的多进程架构也被使用到。 每个 Electron 中的 web 页面运行在它的叫**渲染进程**的进程中。

在普通的浏览器中，web页面无法访问操作系统的原生资源。 然而 `Electron `的用户在 `Node.js `的 API 支持下可以在页面中和操作系统进行一些底层交互。

```js
app.on('ready', () => {
    const mainWindow = new electron.BrowserWindow({
        width: 800,
        height: 800
    })
    mainWindow.loadFile('./src/index.html');
    
    const mainWindow2 = new electron.BrowserWindow({
        width: 800,
        height: 800
    })
    mainWindow2.loadFile('./src/index2.html');
})
```



## 2、打开渲染进程调试

我们可以在窗口中使用`ctrl+shift+i`打开进程调试窗口，如果想要在渲染是自动打开（默认打开调试）则需要添加`mainWindow2.webContents.openDevTools()`

```js
// 打开第二个窗口渲染进程
mainWindow2.webContents.openDevTools()
```

<img src="image/image-20220724001409641.png" alt="image-20220724001409641" style="zoom:67%;" />

# 六、自定义原生菜单

## 5.1 自定义菜单

详细文档：https://www.electronjs.org/docs/api/menu

```js
const electron = require('electron')

const { app, Menu } = electron
const template = [
  {
    label: '文件',
    submenu: [
      {
        label: '新建窗口'
      }
    ]
  },
  {
    label: '编辑',
    submenu: [
      {
        label: '新建窗口'
      }
    ]
  }
]
const menu = Menu.buildFromTemplate(template)

Menu.setApplicationMenu(menu)
```

## 5.2 给菜单定义点击事件

1、点击打开新窗口

```js
submenu: [
  {
    label: '新建窗口',
    click: ()=>{
      const newMainWindow = new BrowserWindow({
        width: 300,
        height: 300
      })
      newMainWindow.loadFile('./new.html')
    }
  }
]
```

2、点击打开浏览器

`shell` 模块提供了集成其他桌面客户端的关联功能.

```js
const { BrowserWindow, Menu, shell } = require('electron')
const template = [
  {
    label: '文件',
    submenu: [
      {
        label: '文件1',
        click () {
          // 点击打开新窗口
          const mainWindow2 = new BrowserWindow({
            width: 600,
            height: 600
          })
        
          mainWindow2.loadFile('./index.html')
        }
      }
    ]
  },
  {
    label: 'csdn',
    click () {
      // 点击打开浏览器
      shell.openExternal('https://www.csdn.net/')
    }
  }
]
```



## 5.3 抽离菜单定义

```js
const { BrowserWindow, Menu} = require('electron')
const template = [
  {
    label: '文件',
    submenu: [
      {
        label: '新建窗口',
        click: ()=>{
          const newMainWindow = new BrowserWindow({
            width: 300,
            height: 300
          })
          newMainWindow.loadFile('./new.html')
        }
      }
    ]
  },
  {
    label: '编辑',
    submenu: [
      {
        label: '新建窗口'
      }
    ]
  }
]
const menu = Menu.buildFromTemplate(template)

Menu.setApplicationMenu(menu)
```

```js
require('./menu')
```

#### 打开调式

mainWindow.webContents.openDevTools()

## 5.4 自定义顶部菜单

+ 通过frame创建无边框窗口

  ```js
  const mainWindow = new electron.BrowserWindow({
      frame: false
  })
  ```

+ 自定义窗口

  ```html
  <div class="custom-menu">
    <ul>
        <li>新建窗口</li>
        <li>关于我们</li>
      </ul>
    </div>
  ```

  ```css
  * {
    margin: 0;
    padding: 0;
  }
  .custom-menu {
    height: 50px;
    width: 100%;
    background: pink;
  }
  
  .custom-menu ul {
    list-style: none;
  }
  
  .custom-menu ul li {
    float: left;
    width: 50px;
    line-height: 50px;
    text-align: center;
    margin-left: 10px;
  }
  ```

  添加-webkit-app-region: drag;实现拖拽

## 5.5 点击创建新窗口

```js
// html
<li class="new-window">新建窗口</li>

// js
// remote 通过remote使用主进程的方法
const { remote: {BrowserWindow} } = require('electron')
const newWindow = document.querySelector('.new-window')
newWindow.onclick = function () {
  new BrowserWindow({
    width: 200,
    height: 300
  })
}
```

能够在html中使用node方法

```js
const mainWindow = new BrowserWindow({
  width: 800,
  height: 500,
  webPreferences: {
    // 开启node模块
    nodeIntegration: true,
    // 开启remote模块
    enableRemoteModule: true
  }
})
```

## 5.6 点页面打开浏览器

+ html

  ```html
  <a id="a1" href="https://www.itheima.com">打开浏览器</a>
  ```

+ js

  ```js
  const { shell } = require('electron')
  const allA = document.querySelectorAll('a')
  
  allA.forEach(item => {
    item.onclick = function (e) {
      e.preventDefault()
      console.log(item)
      shell.openExternal(item.href)
    }
  })
  ```

# 6. 打开对话框读取文件

## 6.1 读取文件

+ 定义点击事件

  ```js
  <button onclick="openFile()">打开</button>
  ```

+ 定义事件函数

  打开对话框文档：https://www.electronjs.org/docs/api/dialog

  ```js
  // 打开对话框
  function openFile() {
    const res = dialog.showOpenDialogSync({
      title: '选择文件',
      buttonLabel: '哈哈',
      filters: [
        { name: 'Custom File Type', extensions: ['js'] },
    ]
    })
  
    const fileContent = fs.readFileSync(res[0])
    dropEl.innerText = fileContent
  }
  ```

## 6.2 保存文件

+ 定义点击事件

  ```html
  <button onclick="saveFile()">保存</button>
  ```

+ 事件函数

  ```js
  // 保存对话框
  function saveFile() {
    const res = remote.dialog.showSaveDialogSync({
      title: '保存文件',
      buttonLabel: '保存文件',
      filters: [
        { name: 'index', extensions: ['js'] },
      ]
    })
    fs.writeFileSync(res, dropEl.value)
  }
  ```

# 7. 定义快捷键

## 7.1 主线程定义

+ 引入

  ```js
  const { app, BrowserWindow, globalShortcut } = require('electron')
  ```

+ 在ready中注册快捷键

  ```js
  const ret = globalShortcut.register('CommandOrControl+X', () => {
    console.log('CommandOrControl+X is pressed + 打印结果在命令行')
  })
  ```

+ 定义快捷键最大、最小、关闭窗口

  ```js
  globalShortcut.register('CommandOrControl+T',()=>{
      mainWindow.unmaximize();
    })
    globalShortcut.register('CommandOrControl+H',()=>{
      mainWindow.close()
    })
    globalShortcut.register('CommandOrControl+M',()=>{
      mainWindow.maximize()
    })
  ```

## 7.2 渲染进程定义

+ 通过remote注册

  ```js
  // 定义快捷键
  remote.globalShortcut.register('Ctrl+O', () => {
    console.log('ctrl+o')
  })
  ```


# 8. 渲染进程和主线程通讯

+ 定义按钮

  ```html
  <div class="maxWindow no-drag" onclick="maxWindow()"></div>
  ```

+ 事件函数

  ```js
  function maxWindow() {
    ipcRenderer.send('max-window')
  }
  ```

+ 主线程定义事件

  ```js
  ipcMain.on('max-window', () => {
      mainWindow.maximize()
    })
  ```

+ 传参

  ```js
  let windowSize = 'unmax-window'
  function maxWindow() {
    windowSize = windowSize === 'max-window' ?'unmax-window':'max-window'
    ipcRenderer.send('max-window',windowSize)
  }
  ```

+ 接收参数

  ```js
  ipcMain.on('max-window', (event,arg) => {
      console.log(arg)
      if(arg === 'unmax-window') return mainWindow.maximize();
      mainWindow.unmaximize()
    })
  ```

# 09. electron打包

+ 安装electron-packager

  ```js
  cnpm i electron-packager -D
  ```

+ 添加打包任务

  ```js
  "build": "electron-packager ./ HelloWorld --platform=win32 --arch=x64 --out ./outApp --overwrite --icon=./favicon.ico"
  ```

# 10 .electron结合框架开发

+ 利用vue脚手架初始化项目

+ 在项目中安装electron

  cnpm i electron

+ 添加electron启动配置

  ```js
  "main": "main.js",
  "scripts": {
     "start": "react-scripts start",
     "build": "react-scripts build",
     "test": "react-scripts test",
     "eject": "react-scripts eject",
     "electron": "electron ."
    },
  ```

+ 配置main.js

  ```js
  const {app, BrowserWindow} = require('electron')
  
  function createWindow () {
    // Create the browser window.
    const mainWindow = new BrowserWindow({
      width: 800,
      height: 600
    })
    // Open the DevTools.
    // mainWindow.webContents.openDevTools()
  }
  
  app.on('ready', () => {
    createWindow()
  })
  ```

+ 加载vue项目

  ```js
  mainWindow.loadURL('http://localhost:3000/')
  ```

# 