## css3选择器

| 选择器                                                       | 例子                  | 例子描述                                         | CSS  |
| ------------------------------------------------------------ | --------------------- | ------------------------------------------------ | ---- |
| [.class](https://www.w3school.com.cn/cssref/selector_class.asp) | .intro                | 选择 class="intro" 的所有元素。                  | 1    |
| [#id](https://www.w3school.com.cn/cssref/selector_id.asp)    | #firstname            | 选择 id="firstname" 的所有元素。                 | 1    |
| [*](https://www.w3school.com.cn/cssref/selector_all.asp)     | *                     | 选择所有元素。                                   | 2    |
| [element](https://www.w3school.com.cn/cssref/selector_element.asp) | p                     | 选择所有  元素。                                 | 1    |
| [element,element](https://www.w3school.com.cn/cssref/selector_element_comma.asp) | div,p                 | 选择所有  元素和所有  元素。                     | 1    |
| [element element](https://www.w3school.com.cn/cssref/selector_element_element.asp) | div p                 | 选择  元素内部的所有  元素。                     | 1    |
| [element>element](https://www.w3school.com.cn/cssref/selector_element_gt.asp) | div>p                 | 选择父元素为  元素的所有  元素。                 | 2    |
| [element+element](https://www.w3school.com.cn/cssref/selector_element_plus.asp) | div+p                 | 选择紧接在  元素之后的所有  元素。               | 2    |
| [[attribute\]](https://www.w3school.com.cn/cssref/selector_attribute.asp) | [target]              | 选择带有 target 属性所有元素。                   | 2    |
| [[attribute=value\]](https://www.w3school.com.cn/cssref/selector_attribute_value.asp) | [target=_blank]       | 选择 target="_blank" 的所有元素。                | 2    |
| [[attribute~=value\]](https://www.w3school.com.cn/cssref/selector_attribute_value_contain.asp) | [title~=flower]       | 选择 title 属性包含单词 "flower" 的所有元素。    | 2    |
| [[attribute\|=value\]](https://www.w3school.com.cn/cssref/selector_attribute_value_start.asp) | [lang\|=en]           | 选择 lang 属性值以 "en" 开头的所有元素。         | 2    |
| [:link](https://www.w3school.com.cn/cssref/selector_link.asp) | a:link                | 选择所有未被访问的链接。                         | 1    |
| [:visited](https://www.w3school.com.cn/cssref/selector_visited.asp) | a:visited             | 选择所有已被访问的链接。                         | 1    |
| [:active](https://www.w3school.com.cn/cssref/selector_active.asp) | a:active              | 选择活动链接。                                   | 1    |
| [:hover](https://www.w3school.com.cn/cssref/selector_hover.asp) | a:hover               | 选择鼠标指针位于其上的链接。                     | 1    |
| [:focus](https://www.w3school.com.cn/cssref/selector_focus.asp) | input:focus           | 选择获得焦点的 input 元素。                      | 2    |
| [:first-letter](https://www.w3school.com.cn/cssref/selector_first-letter.asp) | p:first-letter        | 选择每个  元素的首字母。                         | 1    |
| [:first-line](https://www.w3school.com.cn/cssref/selector_first-line.asp) | p:first-line          | 选择每个  元素的首行。                           | 1    |
| [:first-child](https://www.w3school.com.cn/cssref/selector_first-child.asp) | p:first-child         | 选择属于父元素的第一个子元素的每个  元素。       | 2    |
| [:before](https://www.w3school.com.cn/cssref/selector_before.asp) | p:before              | 在每个  元素的内容之前插入内容。                 | 2    |
| [:after](https://www.w3school.com.cn/cssref/selector_after.asp) | p:after               | 在每个  元素的内容之后插入内容。                 | 2    |
| [:lang(language)](https://www.w3school.com.cn/cssref/selector_lang.asp) | p:lang(it)            | 选择带有以 "it" 开头的 lang 属性值的每个  元素。 | 2    |
| [element1~element2](https://www.w3school.com.cn/cssref/selector_gen_sibling.asp) | p~ul                  | 选择前面有  元素的每个  元素。                   | 3    |
| [[attribute^=value\]](https://www.w3school.com.cn/cssref/selector_attr_begin.asp) | a[src^="https"]       | 选择其 src 属性值以 "https" 开头的每个  元素。   | 3    |
| [[attribute$=value\]](https://www.w3school.com.cn/cssref/selector_attr_end.asp) | a[src$=".pdf"]        | 选择其 src 属性以 ".pdf" 结尾的所有  元素。      | 3    |
| [[attribute*=value\]](https://www.w3school.com.cn/cssref/selector_attr_contain.asp) | a[src\*="abc"]        | 选择其 src 属性中包含 "abc" 子串的每个  元素。   | 3    |
| [:first-of-type](https://www.w3school.com.cn/cssref/selector_first-of-type.asp) | p:first-of-type       | 选择属于其父元素的首个  元素的每个  元素。       | 3    |
| [:last-of-type](https://www.w3school.com.cn/cssref/selector_last-of-type.asp) | p:last-of-type        | 选择属于其父元素的最后  元素的每个  元素。       | 3    |
| [:only-of-type](https://www.w3school.com.cn/cssref/selector_only-of-type.asp) | p:only-of-type        | 选择属于其父元素唯一的  元素的每个  元素。       | 3    |
| [:only-child](https://www.w3school.com.cn/cssref/selector_only-child.asp) | p:only-child          | 选择属于其父元素的唯一子元素的每个  元素。       | 3    |
| [:nth-child(n)](https://www.w3school.com.cn/cssref/selector_nth-child.asp) | p:nth-child(2)        | 选择属于其父元素的第二个子元素的每个  元素。     | 3    |
| [:nth-last-child(n)](https://www.w3school.com.cn/cssref/selector_nth-last-child.asp) | p:nth-last-child(2)   | 同上，从最后一个子元素开始计数。                 | 3    |
| [:nth-of-type(n)](https://www.w3school.com.cn/cssref/selector_nth-of-type.asp) | p:nth-of-type(2)      | 选择属于其父元素第二个  元素的每个  元素。       | 3    |
| [:nth-last-of-type(n)](https://www.w3school.com.cn/cssref/selector_nth-last-of-type.asp) | p:nth-last-of-type(2) | 同上，但是从最后一个子元素开始计数。             | 3    |
| [:last-child](https://www.w3school.com.cn/cssref/selector_last-child.asp) | p:last-child          | 选择属于其父元素最后一个子元素每个  元素。       | 3    |
| [:root](https://www.w3school.com.cn/cssref/selector_root.asp) | :root                 | 选择文档的根元素。                               | 3    |
| [:empty](https://www.w3school.com.cn/cssref/selector_empty.asp) | p:empty               | 选择没有子元素的每个  元素（包括文本节点）。     | 3    |
| [:target](https://www.w3school.com.cn/cssref/selector_target.asp) | #news:target          | 选择当前活动的 #news 元素。                      | 3    |
| [:enabled](https://www.w3school.com.cn/cssref/selector_enabled.asp) | input:enabled         | 选择每个启用的  元素。                           | 3    |
| [:disabled](https://www.w3school.com.cn/cssref/selector_disabled.asp) | input:disabled        | 选择每个禁用的  元素                             | 3    |
| [:checked](https://www.w3school.com.cn/cssref/selector_checked.asp) | input:checked         | 选择每个被选中的  元素。                         | 3    |
| [:not(selector)](https://www.w3school.com.cn/cssref/selector_not.asp) | :not(p)               | 选择非  元素的每个元素。                         | 3    |
| [::selection](https://www.w3school.com.cn/cssref/selector_selection.asp) | ::selection           | 选择被用户选取的元素部分。                       | 3    |

## CSS3属性

| 类型                                      | 属性                                                         | 描述                                             |
| ----------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------ |
| 动画属性（Animation）                     | animation-name                                               | 指定要绑定到选择器的关键帧的名称                 |
| animation-duration                        | 动画指定需要多少秒或毫秒完成                                 |                                                  |
| animation-timing-function                 | 设置动画将如何完成一个周期                                   |                                                  |
| animation-delay                           | 设置动画在启动前的延迟间隔。                                 |                                                  |
| animation-iteration-count                 | 定义动画的播放次数。                                         |                                                  |
| animation-direction                       | 指定是否应该轮流反向播放动画。                               |                                                  |
| animation-fill-mode                       | 规定当动画不播放时（当动画完成时，或当动画有一个延迟未开始播放时），要应用到元素的样式。 |                                                  |
| animation-play-state                      | 指定动画是否正在运行或已暂停。                               |                                                  |
| initial                                   | 设置属性为其默认值。                                         |                                                  |
| inherit                                   | 从父元素继承属性。                                           |                                                  |
| 背景属性（Background）                    | background-color                                             | 指定要使用的背景颜色                             |
| background-position                       | 指定背景图像的位置                                           |                                                  |
| background-size                           | 指定背景图片的大小                                           |                                                  |
| background-repeat                         | 指定如何重复背景图像                                         |                                                  |
| background-origin                         | 指定背景图像的定位区域                                       |                                                  |
| background-clip                           | 指定背景图像的绘画区域                                       |                                                  |
| background-attachment                     | 设置背景图像是否固定或者随着页面的其余部分滚动。             |                                                  |
| background-image                          | 指定要使用的一个或多个背景图像                               |                                                  |
| Border边框属性                            | border                                                       | 简写属性，用于把针对四个边的属性设置在一个声明。 |
| border-style                              | 用于设置元素所有边框的样式，或者单独地为各边设置边框样式。   |                                                  |
| border-width                              | 简写属性，用于为元素的所有边框设置宽度，或者单独地为各边边框设置宽度。 |                                                  |
| border-color                              | 简写属性，设置元素的所有边框中可见部分的颜色，或为 4 个边分别设置颜色。 |                                                  |
| border-bottom                             | 简写属性，用于把下边框的所有属性设置到一个声明中。           |                                                  |
| border-bottom-color                       | 设置元素的下边框的颜色。                                     |                                                  |
| border-bottom-style                       | 设置元素的下边框的样式。                                     |                                                  |
| border-bottom-width                       | 设置元素的下边框的宽度。                                     |                                                  |
| border-left                               | 简写属性，用于把左边框的所有属性设置到一个声明中。           |                                                  |
| border-left-color                         | 设置元素的左边框的颜色。                                     |                                                  |
| border-left-style                         | 设置元素的左边框的样式。                                     |                                                  |
| border-left-width                         | 设置元素的左边框的宽度。                                     |                                                  |
| border-right                              | 简写属性，用于把右边框的所有属性设置到一个声明中。           |                                                  |
| border-right-color                        | 设置元素的右边框的颜色。                                     |                                                  |
| border-right-style                        | 设置元素的右边框的样式。                                     |                                                  |
| border-right-width                        | 设置元素的右边框的宽度。                                     |                                                  |
| border-top                                | 简写属性，用于把上边框的所有属性设置到一个声明中。           |                                                  |
| border-top-color                          | 设置元素的上边框的颜色。                                     |                                                  |
| border-top-style                          | 设置元素的上边框的样式。                                     |                                                  |
| border-top-width                          | 设置元素的上边框的宽度。                                     |                                                  |
| Outline边框属性                           | outline                                                      | 在一个声明中设置所有的轮廓属性                   |
| outline-color                             | 设置轮廓的颜色                                               |                                                  |
| outline-style                             | 设置轮廓的样式                                               |                                                  |
| outline-width                             | 设置轮廓的宽度                                               |                                                  |
| Box 属性                                  | overflow-x                                                   | 如果内容溢出，是否对左右进行剪裁                 |
| overflow-y                                | 如果内容溢出，是否对上下进行剪裁                             |                                                  |
| overflow-style                            | 内容溢出首选滚动方式                                         |                                                  |
| rotation                                  | 围绕rotation-poin定义的点对元素进行旋转                      |                                                  |
| rotation-poin                             | 偏移点                                                       |                                                  |
| Color属性                                 | color-profile                                                | 允许使用源的颜色配置文件的默认以外的规范         |
| opacity                                   | 规定书签的级别                                               |                                                  |
| box-shadow阴影                            | h-shadow                                                     | 阴影的水平方向偏移的距离                         |
| v-shadow                                  | 阴影的垂直方向偏移的距离                                     |                                                  |
| blur                                      | 模糊的半径距离                                               |                                                  |
| spread                                    | 阴影的额外增加的尺寸                                         |                                                  |
| color                                     | 阴影的颜色                                                   |                                                  |
| inset                                     | 切换为内部阴影                                               |                                                  |
|                                           | text-overflow                                                | 设置当文本溢出元素框时的处理方式                 |
|                                           | ellipsis                                                     | 显示省略号                                       |
|                                           | word-break                                                   | 自动换行的方式                                   |
|                                           | word-wrap                                                    | 单词的换行方式                                   |
| transform属性                             | none                                                         | 定义不进行转换。                                 |
| matrix(n,n,n,n,n,n)                       | 定义 2D 转换，使用六个值的矩阵。                             |                                                  |
| matrix3d(n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n) | 定义 3D 转换，使用 16 个值的 4x4 矩阵。                      |                                                  |
| translate(x,y)                            | 定义 2D 转换。                                               |                                                  |
| translate3d(x,y,z)                        | 定义 3D 转换。                                               |                                                  |
| translateX(x)                             | 定义转换，只是用 X 轴的值。                                  |                                                  |
| translateY(y)                             | 定义转换，只是用 Y 轴的值。                                  |                                                  |
| translateZ(z)                             | 定义 3D 转换，只是用 Z 轴的值。                              |                                                  |
| scale(x[,y]?)                             | 定义 2D 缩放转换。                                           |                                                  |
| scale3d(x,y,z)                            | 定义 3D 缩放转换。                                           |                                                  |
| scaleX(x)                                 | 通过设置 X 轴的值来定义缩放转换。                            |                                                  |
| scaleY(y)                                 | 通过设置 Y 轴的值来定义缩放转换。                            |                                                  |
| scaleZ(z)                                 | 通过设置 Z 轴的值来定义 3D 缩放转换。                        |                                                  |
| rotate(angle)                             | 定义 2D 旋转，在参数中规定角度。                             |                                                  |
| rotate3d(x,y,z,angle)                     | 定义 3D 旋转。                                               |                                                  |
| rotateX(angle)                            | 定义沿着 X 轴的 3D 旋转。                                    |                                                  |
| rotateY(angle)                            | 定义沿着 Y 轴的 3D 旋转。                                    |                                                  |
| rotateZ(angle)                            | 定义沿着 Z 轴的 3D 旋转。                                    |                                                  |
| skew(x-angle,y-angle)                     | 定义沿着 X 和 Y 轴的 2D 倾斜转换。                           |                                                  |
| skewX(angle)                              | 定义沿着 X 轴的 2D 倾斜转换。                                |                                                  |
| skewY(angle)                              | 定义沿着 Y 轴的 2D 倾斜转换。                                |                                                  |
| perspective(n)                            | 为 3D 转换元素定义透视视图。                                 |                                                  |