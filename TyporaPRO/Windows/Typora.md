Typora 是不错的 Markdown 编辑器啊，但是无奈原本的主题有点丑，所以自己改造一下。

使用系统主题
打开 Typora 偏好设置的外观，点击获取主题即可进入主题官网。找到自己喜欢的下载。



点击上图的 打开主题文件夹，会打开 Typora 存放主题的文件夹，之后讲下载的主题放入该文件夹内。



之后重启 Typora 即可在更换主题的菜单找到下载的主题。

要是官网的主题不好看怎么办？？

自己修改主题
在主题文件夹内找到自己想修改的主题样式。比如我修改的 GitHub.css。



打开之后进行修改相关内容即可。

此处放上我修改的样式。主要是改了一下颜色，边框等等。

```css


:root {
    /*Sidebar整体的背景颜色*/
    --side-bar-bg-color: #fafafa;
    /*Sidebar未选中文件名的颜色*/
    --control-text-color: #3b454e;
    /*Sidebar选中文件的背景颜色*/
    --active-file-bg-color: #e6ecf1;
    /*Sidebar选中文件的字体颜色*/
    --active-file-text-color: inherit;
    --active-file-border-color: #15ac8e;

    --monospace: 'Menlo', monospace;
}

@include-when-export url(https://fonts.loli.net/css?family=Open+Sans:400italic,700italic,700,400&subset=latin,latin-ext);

@font-face {
    font-family: 'Open Sans';
    font-style: normal;
    font-weight: normal;
    src: local('Open Sans Regular'),url('./github/400.woff') format('woff');
}

@font-face {
    font-family: 'Open Sans';
    font-style: italic;
    font-weight: normal;
    src: local('Open Sans Italic'),url('./github/400i.woff') format('woff');
}

@font-face {
    font-family: 'Open Sans';
    font-style: normal;
    font-weight: bold;
    src: local('Open Sans Bold'),url('./github/700.woff') format('woff');
}

@font-face {
    font-family: 'Open Sans';
    font-style: italic;
    font-weight: bold;
    src: local('Open Sans Bold Italic'),url('./github/700i.woff') format('woff');
}



html {
    /*正文字体大小*/
    font-size: 13.5px;
}

body {
    /* 修改整个页面的背景颜色 */
    background-color: #ffffff;
    /* --monospace:  "Iosevka Curly Medium", HYZhengYuan, "JetBrains Mono", monospace; */
    /* font-family: "Microsoft YaHei", "Open Sans","Clear Sans","Helvetica Neue",Helvetica,Arial,sans-serif;/ */
    font-family: "Microsoft YaHei","Clear Sans","Helvetica Neue",Helvetica,Arial,sans-serif;
    color: rgb(0, 0, 0);
    /* 正文行高 */
    line-height: 1.6;
}

#write {
    max-width: 900px;
    margin: 0 auto;
    padding: 20px;
    padding-bottom: 100px;
}
#write > ul:first-child,
#write > ol:first-child{
    margin-top: 30px;
}

a {
    color: #4183C4;
}
h1,
h2,
h3,
h4,
h5,
h6 {
    position: relative;
    margin-top: 1rem;
    margin-bottom: 1rem;
    font-weight: bold;
    line-height: 1.4;
    cursor: text;
}
h1:hover a.anchor,
h2:hover a.anchor,
h3:hover a.anchor,
h4:hover a.anchor,
h5:hover a.anchor,
h6:hover a.anchor {
    text-decoration: none;
}
h1 tt,
h1 code {
    font-size: inherit;
}
h2 tt,
h2 code {
    font-size: inherit;
}
h3 tt,
h3 code {
    font-size: inherit;
}
h4 tt,
h4 code {
    font-size: inherit;
}
h5 tt,
h5 code {
    font-size: inherit;
}
h6 tt,
h6 code {
    font-size: inherit;
}

/* 修改高亮文本的属性 */
mark {
    background: #ffeb11;
    color: #4e4b4b;
}

/* 修改各级标题样式 */
h1 {
    padding-bottom: .3em;
    font-size: 1.7em;
    line-height: 1.1;
    color: #660066;
    /* 修改标题下面的横线样式 */
    /*border-bottom: 2px solid #E3170D;*/
        /* 居中 */
    text-align: left;
}
h2 {
    padding-bottom: .3em;
    font-size: 1.6em;
    line-height: 1.1;
    color: #FF4500;
    /*border-bottom: 1px solid #D3D3D3;*/
        /* 居中 */
    text-align: left;
}
h3 {
    font-size: 1.5em;
    color: #fc7600;
    line-height: 1.1;
    text-align: left;
    /*border-bottom: 1.5px solid #CC3333;*/
}

h4 {
    font-size: 1.3em;
    color: #033aa7;
}

h5 {
    font-size: 1.2em;
    color: #018c8c;
}
h6 {
   font-size: 1.1em;
    color: #366804;
}
p,
blockquote,
ul,
ol,
dl,
table{
    margin: 0.8em 0;
}
li>ol,
li>ul {
    margin: 0 0;
     /* 侧边栏目录字体颜色 */
    color: #264e60;
}
hr {
    height: 2px;
    padding: 0;
    margin: 16px 0;
    background-color: #e7e7e7;
    border: 0 none;
    overflow: hidden;
    box-sizing: content-box;
}

li p.first {
    display: inline-block;
}
/*设置点号的字体颜色*/
ul{
    color: #000000;
}
ol {
    padding-left: 30px;
}
ul:first-child,
ol:first-child {
    margin-top: 0;
}
ul:last-child,
ol:last-child {
    margin-bottom: 0;
}


/*修改引用块的样式*/
blockquote {
    border-left: 4px solid #FF6633;
    padding: 0 15px;
    color: #9a09c3;
}
blockquote blockquote {
    padding-right: 0;
}
table {
    padding: 0;
    word-break: initial;
}

/*表格整体的四周线宽属性属性*/
table tr {
    border-top: 1.3px solid #4a1d1d;
    border-left: 1.3px solid #663333;
    border-right: 1.3px solid #663333;
    border-bottom: 1.3px solid #663333;
    margin: 0;
    padding: 0;
}

table tr:nth-child(2n),
thead {
    background-color: #F5F5F5;
}

/*表格第一行属性单独设置*/
table tr th {
    font-weight: bold;
    /*表格边框颜色*/
    border: 1px solid #898888;
    border-bottom: 0;
    margin: 0;
    padding: 6px 13px;
    background-color: #eaebf2;
}

/*表格内容行属性单独设置*/
table tr td {
    border: 1px solid #696969;
    margin: 0;
    padding: 6px 13px;
}

/*图片设置*/
img {
    /*四周圆弧大小*/
    border-radius: 5px;
}


table tr th:first-child,
table tr td:first-child {
    margin-top: 0;
}
table tr th:last-child,
table tr td:last-child {
    margin-bottom: 0;
}

.CodeMirror-lines {
    padding-left: 4px;
}

.code-tooltip {
    box-shadow: 0 1px 1px 0 rgba(0,28,36,.3);
    border-top: 1px solid #eef2f2;
}
 
 a {
     /*color：正文目录字体颜色*/
     color: rgb(21, 25, 157);
 }
 [md-inline] a {
    background-color: #4d4d4d;
    color: #fff;
    text-decoration: none;
    padding: 4px;
    border-radius: 4px;
    font-size: 0.9rem;
 }
 
.md-fences,
code,
tt {
    /* 代码块边框的颜色和线宽 */
    border: 1px solid #808080;
    background-color: #f8f8f8;
    border-radius: 0.5rem;
    padding: 0.3rem;
    padding: 2px 4px 0px 4px;
    /* 代码字体大小 */
    font-size: 1em;
    /* 指定代码字体家族,这里用的IDEA的MONO,需要在MAC系统上安装 */
    font-family: var(--monospace);
    line-height: 1.6;
}

code {
    background-color: #f3f4f4;
    padding: 0 2px 0 2px;
}

.md-fences {
    margin-bottom: 15px;
    margin-top: 15px;
    padding-top: 8px;
    padding-bottom: 6px;
}



.md-task-list-item > input {
  margin-left: -1.3em;
}

@media print {
    html {
        font-size: 13px;
    }
    table,
    pre {
        page-break-inside: avoid;
    }
    pre {
        word-wrap: break-word;
    }
}

.md-fences {
    background-color: #f8f8f8;
}
#write pre.md-meta-block {
    padding: 1rem;
    font-size: 85%;
    line-height: 1.45;
    background-color: #f7f7f7;
    border: 0;
    border-radius: 3px;
    color: #777777;
    margin-top: 0 !important;
}

.mathjax-block>.code-tooltip {
    bottom: .375rem;
}

.md-mathjax-midline {
    background: #fafafa;
}

#write>h3.md-focus:before{
    left: -1.5625rem;
    top: .375rem;
}
#write>h4.md-focus:before{
    left: -1.5625rem;
    top: .285714286rem;
}
#write>h5.md-focus:before{
    left: -1.5625rem;
    top: .285714286rem;
}
#write>h6.md-focus:before{
    left: -1.5625rem;
    top: .285714286rem;
}
.md-image>.md-meta {
    /*border: 1px solid #ddd;*/
    border-radius: 3px;
    padding: 2px 0px 0px 4px;
    font-size: 0.9em;
    color: inherit;
}

.md-tag {
    color: #a7a7a7;
    opacity: 1;
}

.md-toc { 
    margin-top:20px;
    padding-bottom:20px;
}

.sidebar-tabs {
    border-bottom: none;
}

#typora-quick-open {
    border: 1px solid #ddd;
    background-color: #f8f8f8;
}

#typora-quick-open-item {
    background-color: #FAFAFA;
    border-color: #FEFEFE #e5e5e5 #e5e5e5 #eee;
    border-style: solid;
    border-width: 1px;
}

/** focus mode */
.on-focus-mode blockquote {
    border-left-color: rgba(85, 85, 85, 0.12);
}

header, .context-menu, .megamenu-content, footer{
    font-family: "Segoe UI", "Arial", sans-serif;
}

.file-node-content:hover .file-node-icon,
.file-node-content:hover .file-node-open-state{
    visibility: visible;
}

.mac-seamless-mode #typora-sidebar {
    background-color: #fafafa;
    background-color: var(--side-bar-bg-color);
}

.md-lang {
    color: #14b6cc;
}

.html-for-mac .context-menu {
    --item-hover-bg-color: #E6F0FE;
}

#md-notification .btn {
    border: 0;
}

.dropdown-menu .divider {
    border-color: #e5e5e5;
}

.ty-preferences .window-content {
    background-color: #fafafa;
}

.ty-preferences .nav-group-item.active {
    color: white;
    background: #999;
}







```

最后重启即可