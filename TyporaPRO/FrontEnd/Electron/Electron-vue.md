# 一、使用Electron-vue构建项目

值的注意的是该项目在2019年已经停止维护

[项目地址](https://github.com/SimulatedGREG/electron-vue)

[项目文档](https://simulatedgreg.gitbooks.io/electron-vue/content/cn/)

### 1、什么是Electron-vue

为了要避免使用 vue 手动建立起 electron 应用程序。electron-vue 充分利用 `vue-cli` 作为脚手架工具，加上拥有 `vue-loader` 的 `webpack`、`electron-packager` 或是 `electron-builder`，以及一些最常用的插件，如`vue-router`、`vuex` 

### 2、特点

- 基本的项目结构与 **单一的** `package.json` 设置
- 详细的 [文档](https://simulatedgreg.gitbooks.io/electron-vue/content/)
- 使用 [vue-cli](https://github.com/vuejs/vue-cli) 作为项目脚手架
- 立即可用的 Vue 插件 ([axios](https://github.com/mzabriskie/axios), [vue-electron](https://github.com/SimulatedGREG/vue-electron), [vue-router](https://github.com/vuejs/vue-router), [vuex](https://github.com/vuejs/vuex))*
- 预装开发工具 [vue-devtools](https://github.com/vuejs/vue-devtools) 和 [devtron](https://github.com/electron/devtron)
- 使用 [electron-packager](https://github.com/electron-userland/electron-packager) 或 [electron-builder](https://github.com/electron-userland/electron-builder) 轻松打包你的应用程序*
- `appveyor.yml` 与 `.travis.yml` 配置用于 [electron-builder](https://github.com/electron-userland/electron-builder) 的自动部署*
- 能够生成用于浏览器的网页输出
- 便利的 [NPM 脚本](https://simulatedgreg.gitbooks.io/electron-vue/content/cn/npm_scripts.html)
- 使用携带模块热更新 (Hot Module Replacement) 的 [webpack](https://github.com/webpack/webpack) 和 [vue-loader](https://github.com/vuejs/vue-loader)
- 在工作在 electron 的 `main` 主进程时重启进程
- 支持使用 [vue-loader](https://github.com/vuejs/vue-loader/) 的 HTML/CSS/JS 预处理器
- 默认支持 [`stage-0`](https://babeljs.io/docs/plugins/preset-stage-0/) 的 ES6
- 使用 [`babili`](https://github.com/babel/babili) 避免完全反编译到 ES5
- ESLint (支持 [`standard`](https://github.com/feross/standard) 和 [`airbnb-base`](https://github.com/airbnb/javascript))*
- 单元测试 (使用 Karma + Mocha)*
- 端到端测试 (使用 Spectron + Mocha)*

### 二、基础搭建

该样板代码被构建为 [`vue-cli`](https://github.com/vuejs/vue-cli) 的一个模板，并且包含多个选项，可以自定义你最终的脚手架程序。本项目需要使用 `node@^7` 或更高版本。electron-vue 官方推荐 [`yarn`](https://yarnpkg.org/) 作为软件包管理器，因为它可以更好地处理依赖关系，并可以使用 `yarn clean` 帮助减少最后构建文件的大小。

```sh
# 安装 vue-cli 和 脚手架样板代码
npm install -g vue-cli
npm install -g @vue/cli-init
vue init simulatedgreg/electron-vue ele-vue

# 安装依赖并运行你的程序
cd my-project
yarn # 或者 npm install
yarn run dev # 或者 npm run dev
```

# 二、手动搭建

## 1、安装VUE

使用vue-cli来搭建

```sh
npm install @vue/cli -g
npm install @vue/cli-service -g
```

创建项目

```sh
vue create ele-vue3
```

Vue3选默认的第二项，或者选手动配置的第三项。默认的第二项没有 `Vue-Router` 和 `Vuex`，所以这里要选第三项，我们手动勾选

注意：最后选 Vue的版本，根据提示选择，最后进入文件夹目录，运行`npm run serve`看是否成功启动

```
cd ele-vue3
```

## 2、集成 Electron

我们使用 `Vue CLI Plugin Electron Builder`来集成Electron，只需要一步

```sh
# 在项目下命令行执行
vue add electron-builder 
```













































































