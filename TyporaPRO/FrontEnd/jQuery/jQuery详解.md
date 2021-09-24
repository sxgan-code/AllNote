# 一、jQuery核心

## 1、jQuery() 函数

`jQuery()`函数是jQuery库的最核心函数，jQuery的一切都是基于此函数的。该函数==主要用于获取HTML DOM元素并将其封装为jQuery对象，以便于使用jQuery对象提供的其他属性和方法对DOM元素进行操作==。

jQuery()函数的功能非常强大，它可以将各种类型的参数智能地封装为jQuery对象。

语法

`jQuery()`函数的功能非常强大，因此用法也比较复杂，其主要用法如下：

**用法一**：

*JavaScript:*

```js
jQuery( selector, [ context ] )
```

将选择器字符串`selector`所对应的HTML DOM元素封装为jQuery对象。可选参数`context`用于指定查找DOM元素的范围。**
**

**用法二**：

*JavaScript:*

```js
// jQuery 1.4 新增省略参数obj的用法：不传入任何参数，将返回空的jQuery对象
jQuery( [ obj ] )
```

将指定对象`obj`封装为jQuery对象。这个对象可以是一个DOM元素(`Element`)，也可以是一个DOM元素数组，也可以是一个jQuery对象(对其进行克隆)，或者其他对象。你也可以省略该参数，从而返回一个空的jQuery对象。**
**

**用法三**：

*JavaScript:*

```js
jQuery( html, [ ownerDocument ] )
```

根据HTML标签字符串`html`动态地创建临时DOM元素，并将其封装为jQuery对象。可选参数`ownerDocument`用于指定临时DOM元素在哪个文档中创建(如果存在多个文档的话，例如框架页面)。**
**

**用法四**：jQuery 1.4 新增该用法。

*JavaScript:*

```js
// v1.4 新增
jQuery( html, properties )
```

根据HTML标签字符串`html`和包含其附加属性、事件以及方法的`properties`对象，动态地创建临时DOM元素，并将其封装为jQuery对象。**
**

**用法五**：

*JavaScript:*

```js
jQuery( callback )
```

在当前文档载入完成后，执行指定的函数`callback`。该用法是ready()函数如下用法的简写：`jQuery(document).ready(callback)`。

参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数          | 描述                                                         |
| :------------ | :----------------------------------------------------------- |
| selector      | Number类型指定的选择器字符串，用于查找对应的DOM元素。        |
| context       | 可选/Object类型指定选择器字符串的查找范围，可以是DOM元素、DOM元素数组、文档、jQuery对象。如果省略该参数，默认为当前文档。 |
| obj           | 可选/Object类型指定的对象，用于封装为jQuery对象。可以是DOM元素、DOM元素数组、文档、jQuery对象等。 |
| html          | Object类型指定的HTML标签字符串，例如"<div/>"、"<div></div>"、"<div id='tagId'></div>"(标签中也可以嵌套标签，只要符合html语法即可)。 |
| ownerDocument | Number类型指定DOM元素在哪个文档上进行临时创建，默认为当前文档。 |
| properties    | Object类型指定的对象，用于指定DOM元素的属性、事件和方法。例如：{name:"username", "click":function(){}} |
| callback      | Number类型指定的函数，用于在DOM文档加载完成后立即执行。      |

**返回值**

jQuery()函数的**返回值**是jQuery类型，返回一个jQuery对象。

示例&说明

由于`jQuery()`函数较为复杂，此处将使用较大的篇幅对上述用法进行一一介绍。

#用法一

*JavaScript:*

```js
// 选择当前文档中所有的p标签DOM元素
$("p");

// 选择id属性为username的DOM元素
$("#username");

// 选择所有包含test样式的DOM元素，(例如：class="test")
$(".test");

// 选择所有p标签中带test样式的DOM元素
$("p .test");
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-jquery-demo-1)

#用法二

*JavaScript:*

```js
var dom = document.getElementById("username");
// 将DOM元素封装为jQuery对象
$(dom);

var doms = document.getElementsByName("book_id");
// 将DOM元素数组封装为jQuery对象
$(doms);

// 将body元素封装为jQuery对象
$(document.body);
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-jquery-demo-2)

#用法三

*JavaScript:*

```js
// 创建一个空的span标签的临时DOM元素，并将其封装为jQuery对象
// 以下三种方式的效果一致
$('<span/>');
$('<span></span>');
$('<span>'); // 但不推荐使用这种方式

// 创建一个p标签，内部包含带有test样式的span标签
$('<p><span class="test"></span></p>');

// 创建一个表格
var html = '<table>';
html += '<tr>';
html += '<td>单元格1</td>';
html += '<td>单元格2</td>';
html += '</tr>';
html += '<tr>';
html += '<td>单元格3</td>';
html += '<td>单元格1</td>';
html += '</tr>';
html += '</table>';
$(html);
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-jquery-demo-3)

#用法四

*JavaScript:*

```js
// 创建一个临时的链接jQuery对象
var tempLink = $('<a/>', {
	id: 'goback',
	title: 'CodePlayer',
	html: 'CodePlayer', // 表示链接的锚文本，也就是innerHTML的值
	href: 'https://codeplayer.vip/',
	click: function(){
		// 统计点击次数		
	}
});
// 追加到body标签内容的末尾
tempLink.appendTo("body");


$('<input/>', {
	type: 'checkbox',
	val: 'def', // 表示表单元素的value属性值或textarea的输入内容
	click: function(){
		alert("点击了复选框");
	}
}).appendTo("body");
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-jquery-demo-4)

#用法五

*JavaScript:*

```js
$(function(){
	// 本文档页面载入完成后自动执行
	alert("文档加载完毕!");
});

// 这相当于ready()函数如下用法的简写

$(document).ready(function(){
	// 本文档页面载入完成后自动执行
	alert("文档加载完毕!");
});
```

## 2、jQuery.noConflict() 函数

`jQuery.noConflict()`函数用于**==让出jQuery库对变量$(和变量jQuery)的控制权==**。

一般情况下，在jQuery库中，变量`$`是变量`jQuery`的别名，它们之间是等价的，例如`jQuery("p")`和`$("p")`是等价的。由于变量`$`只有一个字符，并且特点鲜明，因此我们更加习惯使用`$`来操作jQuery库。

不过，其他JS库也可能使用变量`$`来进行操作，例如Prototype库。这个时候两个库可能会由于变量`$`的控制权问题而发生冲突。

此时，你可以使用该函数让出jQuery库对变量`$`的控制权，将该变量交给上一个实现它的JS库，之后我们只能使用变量`jQuery`来操作jQuery库。

此外，使用该函数，还可以同时让出变量`$`和变量`jQuery`的控制权，从而实现多个不同版本的jQuery库共存(详情见下面的示例说明)。

该函数属于全局`jQuery`对象。

语法

静态函数`jQuery.noConflict()`的语法如下：

*JavaScript:*

```js
jQuery.noConflict( [ removeAll ] )
```

参数

| 参数      | 描述                                                         |
| :-------- | :----------------------------------------------------------- |
| removeAll | 可选/Boolean类型是否彻底移交对变量jQuery的控制权，默认为`false`。 |

如果省略了参数`removeAll`或该参数不为`true`，则表示只让出对变量`$`的控制权；如果该参数为`true`，则表示同时让出变量`$`和`jQuery`的控制权。

**返回值**

`jQuery.noConflict()`函数的**返回值**是jQuery类型，返回变量`jQuery`的引用。

示例&说明

以下是加载Prototype和jQuery库的情况：

*JavaScript:*

```js
<script type="text/javascript" src="prototype.js"></script>
<script type="text/javascript" src="jquery.js"></script>
<script type="text/javascript">
// 让出对变量$的控制权
jQuery.noConflict();

// 使用jQuery进行DOM操作
jQuery("#uname").hide();

// 使用Prototype进行DOM操作
$("myDiv").setStyle( {color: "#ffffff"} );
</script>
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery_noconflict-demo) (以下代码请自行到演示页面运行，注意不要同时执行，请分别执行)

此外，我们还可以使用其他自定义的变量名来操作jQuery：

*JavaScript:*

```js
// 让出对变量$的控制权，并将jQuery赋给新的别名j
var j = jQuery.noConflict();

// 基于jQuery进行DOM操作(使用变量j)
j("#uname").hide();

// 基于Prototype进行DOM操作
$("myDiv").setStyle( {color: "#ffffff"} );
```

即使是多个库共存，我们也可以在`jQuery.ready()`的回调函数或其他自定义函数中将局部变量`$`作为jQuery的别名使用：

*JavaScript:*

```js
// 让出jQuery库对变量$的控制权
jQuery.noConflict();

jQuery(document).ready(function($){
	// 使用局部变量$进行jQuery操作
	$("p").css("color", "");	
});


(function($){
	// 使用局部变量$进行jQuery操作
	$("ul li").addClass("item");	
}(jQuery));
```

如果要实现两个版本的jQuery库共存，我们可以编写如下代码：

*JavaScript:*

```js
<script type="text/javascript" src="jquery-1.4.2.js"></script>
<script type="text/javascript" src="jquery-1.11.1.js"></script>
<script type="text/javascript">
// 让出jQuery-1.11.1对变量$和变量jQuery的控制权
var j = jQuery.noConflict( true );

document.writeln( j.fn.jquery ); // 1.11.1

document.writeln( $.fn.jquery ); // 1.4.2
document.writeln( jQuery.fn.jquery ); // 1.4.2

/*
 * 如果前面的jQuery.noConflict()没有传入参数true，
 * 也就是说只让出变量$的控制，则$表示1.4.2，jQuery表示1.11.1
 * 此时，jQuery.fn.jquery为1.11.1
 */
 </script>
```

三个版本的jQuery库共存，对应的jQuery示例代码如下：

*JavaScript:*

```js
<script type="text/javascript" src="jquery-1.4.2.js"></script>
<script type="text/javascript" src="jquery-1.8.3.js"></script>
<script type="text/javascript" src="jquery-1.11.1.js"></script>
<script type="text/javascript">
// 让出jQuery-1.11.1对变量$和变量jQuery的控制权，使用变量j来控制
var j = jQuery.noConflict( true );

// 让出jQuery-1.8.3对变量$的控制权
jQuery.noConflict();

document.writeln( j.fn.jquery ); // 1.11.1
document.writeln( jQuery.fn.jquery ); // 1.8.3
document.writeln( $.fn.jquery ); // 1.4.2
</script>
```

*==注意==*：多个可能存在全局变量重名冲突的JS库，变量的实际控制权一般取决于JS库的加载顺序。以上面三个版本的jQuery库的示例代码为例，后加载的jQuery库的变量覆盖了之前版本的变量，因此每次让出变量的控制权，控制权就会交给上一个JS库。

## 3、jQuery.selector 属性

`selector`属性用于==返回获取当前jQuery对象时传给==[jQuery(selector, context)](https://codeplayer.vip/p/j7sl8)==函数的原始选择器(即`selector`参数)==。

换句话说，你通过什么选择器来获得的当前jQuery对象，当前jQuery对象的`selector`属性就返回什么。

该属性属于`jQuery`对象(实例)。

语法

jQuery1.3 新增该属性，于jQuery 1.7被标识为已过时，并于jQuery 1.9被移除([官方文档](http://api.jquery.com/selector/)是这样描述的。不过在实际测试中发现：该属性在1.9之后的版本中仍然可用。建议谨慎使用，最好不用)。

*JavaScript:*

```js
jQueryObject.selector
```

**返回值**

`selector`属性的**返回值**是String类型，返回该jQuery对象的原始选择器。

如果当前jQuery对象**不是**通过传入选择器字符串来获得的，那么将返回空字符串""。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>	
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $li = $("ul li");
document.writeln( $li.selector ); // ul li

var $p = $("#n1 p");
// 虽然$p是一个空的jQuery对象，没有匹配到任何元素，但也包含了传入的选择器信息
document.writeln( $p.selector ); // #n1 p

var $ul = $("#n1").find("ul");
// jQuery根据我们的操作自动计算出相应的选择器
document.writeln( $ul.selector ); // #n1 ul

var div_n2 = document.getElementById("n2");
var $n2 = $(div_n2); // 以DOM元素的方式获取jQuery对象
document.writeln( $n2.selector ); // (空字符串)
```

## 4、~~jQuery.context 属性~~

`context`属性用于==返回获取当前jQuery对象时传给==[jQuery(selector, context)](https://codeplayer.vip/p/j7sl8)==函数的`context`参数==。

如果当时没有传入`context`参数，则该参数默认为当前文档(`document`)。

该属性属于`jQuery`对象(实例)。

语法

jQuery1.3 新增该属性，但在==jQuery 1.10 中被标识为已过时==。保持该属性只是为了在jQuery Migrate插件中支持`live()`方法的需要，该属性可能会在未来的版本中被移除。

*JavaScript:*

```js
jQueryObject.context
```

**返回值**

`context`属性的**返回值**是Element类型，返回获取该jQuery对象时用于指定查找范围的DOM节点。

如果当时没有指定查找范围，则默认的查找范围为当前文档对象(document)。

`context`属性的**返回值**是Element类型，哪怕当时传入[jQuery(selector, context)](https://codeplayer.vip/p/j7sl8)函数的`context`参数不是Element类型。如果当时传入的`context`参数是jQuery对象，则返回该jQuery对象的`context`属性。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>	
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $li = $("ul li");
// 返回当前文档的document对象
document.writeln( $li.context ); // [object HTMLDocument]
document.writeln( $li.context === document ); // true

var n1 = document.getElementById("n1");
var $n3 = $( "#n3", n1 );
// 返回n1
document.writeln( $n3.context ); // [object HTMLDivElement]
document.writeln( $n3.context === n1 ); // true

var $n2 = $("#n2");
var $n4 = $( "#n4", $n2 );
// 返回$n2的context属性：document对象
document.writeln( $n4.context ); // [object HTMLDocument]
document.writeln( $n4.context === document ); // true

var $n3 = $("#n3", n1);
var $n5 = $( "#n5", $n3 );
// 返回$n3的context属性：n1
document.writeln( $n5.context ); // [object HTMLDivElement]
document.writeln( $n5.context === n1 ); // true
```

## 5、jQuery.length 属性

`length`属性用于**==返回当前jQuery对象封装的元素个数==**。

`length`属性与[size()方法](https://codeplayer.vip/p/j7sn9)的作用相同。

该属性属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.length
```

**返回值**

`length`属性的**返回值**是Number类型，返回该jQuery对象封装的DOM元素的个数。

如果该对象是一个空的jQuery对象，没有封装任何元素，则返回0。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>	
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var j_li = $("ul li");
document.writeln( j_li.length ); // 3

var j_p = $("p"); // 没有p元素，返回空的jQuery对象
document.writeln( j_p.length ); // 0
```

## 6、jQuery.size() 函数

`size()`函数用于**==返回当前jQuery对象封装的元素个数==**。

`size()`函数与[length属性](https://codeplayer.vip/p/j7sn8)的作用相同。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.size( )
```

**返回值**

`size()`函数的**返回值**是Number类型，返回该jQuery对象封装的DOM元素的个数。

如果该对象是一个空的jQuery对象，没有封装任何元素，则返回0。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>	
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var j_li = $("ul li");
document.writeln( j_li.size() ); // 3

var j_p = $("p"); // 没有p元素，返回空的jQuery对象
document.writeln( j_p.size() ); // 0
```

## 7、jQuery.get() 函数

`get()`函数用于**==获取当前jQuery对象匹配到的DOM元素==**。

这里介绍的`get()`函数属于jQuery对象实例，jQuery中还有一个[jQuery.get()](https://codeplayer.vip/p/j7ssb)函数，它属于**全局**的jQuery对象(无需自行创建jQuery对象)，用于通过GET形式的AJAX请求获取远程数据。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.get( [ index ] )
//jQueryObject[index]等价于jQueryObject.get(index)，例如jQueryObject[0]等价于jQueryObject.get(0);
```

参数

| 参数  | 描述                                     |
| :---- | :--------------------------------------- |
| index | 可选/Number类型指定的索引，从0开始算起。 |

如果没有为`get()`函数指定参数`index`，则返回包含所有匹配到的元素的数组；如果指定了索引参数`index`，则只获取对应索引的那个元素。

如果参数`index`为负数，则将其视作`index + jQueryObject.length`。

如果参数`index`超出有效的取值范围，则返回`undefined`。

**返回值**

`get()`方法的**返回值**为Element/Array类型，返回包含所有匹配到的DOM元素数组或指定索引的DOM元素。

如果当前jQuery对象为空(没有匹配任何的元素)，则返回一个空的数组(不包含任何元素)。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>	
</div>
```

我们编写如下jQuery示例代码，来详细介绍`get()`函数。

*JavaScript:*

```js
var $li = $("ul li");
document.writeln( $li.get() ); // [object HTMLLIElement],[object HTMLLIElement],[object HTMLLIElement]
printElement( $li.get(0) ); // LI#n4
printElement( $li.get(2) ); // LI#n6
printElement( $li.get(3) ); // undefined
printElement( $li.get(-1) ); // LI#n6

document.writeln( $("p").get() ); // (实际上是一个空的数组，输出空字符串)
```

## 8、jQuery.index() 函数

`index()`函数用于==获取当前jQuery对象中指定DOM元素的索引值==。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.index( [ object ] )
```

参数

| 参数   | 描述                                               |
| :----- | :------------------------------------------------- |
| object | 可选/String/Element/jQuery类型表示指定元素的对象。 |

jQuery 1.4新增支持：可以不指定`object`参数、`object`参数可以为字符串(选择器)。

参数`object`可以是DOM元素、jQuery对象或字符串。如果参数`object`是字符串，则将其视作jQuery选择器，表示该选择器所匹配的元素。

**返回值**

`index()`方法的**返回值**为Number类型，返回指定元素的索引位置(从0开始算起)。

注意：以下文本描述中的当前元素表示当前jQuery对象的第一个元素。

- 如果没有指定参数`object`，则返回当前元素在其所有同辈元素中的索引位置。
- 如果`object`为String类型，则将其视作选择器，返回当前元素在选择器所匹配的元素中的索引位置。如果该选择器不匹配任何元素或者当前元素不在匹配到的元素内，则返回-1。
- 如果`object`为DOM元素或jQuery对象，则返回该元素(或该jQuery对象中的第一个元素)在当前jQuery对象所匹配的元素中的索引位置。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<span id="n3"></span>
		<ul id="n4">
			<li id="n5">item1</li>
			<li id="n6">item2</li>
			<li id="n7">item3</li>
		</ul>
		<span id="n8"></span>
	</div>	
</div>
```

我们编写如下jQuery示例代码，来详细介绍`index()`函数。

*JavaScript:*

```js
// 省略参数： 返回第一个li元素在所有同辈元素中的索引
document.writeln( $("li").index( ) ); // 0
// 参数为DOM元素： 返回n6在$li中的索引
document.writeln( $("li").index( document.getElementById("n6") ) ); // 1
// 参数为jQuery对象： 返回$("#n7")在$li中的索引
document.writeln( $("li").index( $("#n7") ) ); // 2

// 参数为选择器字符串： 返回$li中的第一个元素(即n5)在选择器"#n4"所匹配的元素中的索引
// 选择器"#n4"匹配的元素只有n4一个，没有n5，因此返回-1
document.writeln( $("li").index( "#n4" ) ); // -1

// 省略参数：n4在同辈元素中的索引，n4之前的同辈元素有一个n3，因此返回索引为1
document.writeln ( $("#n4").index( ) ); // 1

// 参数为选择器字符串：n8在选择器"span"所匹配的元素中的索引
// 选择器"span"匹配n3、n8两个元素，n8是其中的第二个元素，因此返回索引为1
document.writeln ( $("#n8").index( "span" ) ); // 1
```

# 二、选择器

## 0、选择器一览表

jQuery 选择器

以下选择器的棕色部分，表示该部分需要根据实际需要进行设置。这些部分可能是一个选择器、序号、索引或者其他符合要求的表达式(表格中s1s2sN中的蓝色s2也是如此，这里标注为蓝色，以便于与两侧的s1和sN进行区分)。

| 选择器                                                       | 起始版本 | 实例                          | 选取                                                         |
| :----------------------------------------------------------- | :------- | :---------------------------- | :----------------------------------------------------------- |
| ==**基本选择器——根据多个选择器的组合筛选元素**==             |          |                               |                                                              |
| [s1,s2,sN](https://codeplayer.vip/p/j7sld)                   | 1.0      | $("p,div,#abc")               | 所有的p元素、div元素和id="abc"的元素                         |
| [s1s2sN](https://codeplayer.vip/p/j7sm5)                     | 1.0      | $(":radio[name=uid]:checked") | 所有被选中的name="uid"的radio元素                            |
| [ancestor escendant](https://codeplayer.vip/p/j7sle)         | 1.0      | $("p span")                   | <p>标签内的所有<span>元素                                    |
| [parent > child](https://codeplayer.vip/p/j7slf)             | 1.0      | $("p > span")                 | 所有作为<p>标签的直接子元素的<span>元素                      |
| [prev + next](https://codeplayer.vip/p/j7slg)                | 1.0      | $("label + input")            | 所有紧跟在<label>元素后面的那个同辈<input>元素               |
| [prev ~ sibings](https://codeplayer.vip/p/j7slh)             | 1.0      | $("tr#L2 ~ tr")               | 在id="L2"的<tr>元素之后的所有同辈<tr>元素                    |
| **==基本选择器——根据id、class类名、标签名等筛选元素==**      |          |                               |                                                              |
| [*](https://codeplayer.vip/p/j7slc)                          | 1.0      | $("*")                        | 所有元素                                                     |
| [#id](https://codeplayer.vip/p/j7sl9)                        | 1.0      | $("#abc")                     | id="abc"的元素                                               |
| [.className](https://codeplayer.vip/p/j7slb)                 | 1.0      | $(".post")                    | 所有包含类名"post"的元素                                     |
| [tagName](https://codeplayer.vip/p/j7sla)                    | 1.0      | $("p")                        | 所有<p>元素                                                  |
| **==伪类选择器——根据元素在匹配到的所有元素中的特定次序筛选元素==** |          |                               |                                                              |
| [:first](https://codeplayer.vip/p/j7sli)                     | 1.0      | $("p:first")                  | 第一个<p>标签                                                |
| [:last](https://codeplayer.vip/p/j7slj)                      | 1.0      | $("p:last")                   | 最后一个<p>标签                                              |
| [:even](https://codeplayer.vip/p/j7slp)                      | 1.0      | $("tr:even")                  | 所有偶数<tr>标签                                             |
| [:odd](https://codeplayer.vip/p/j7slo)                       | 1.0      | $("tr:odd")                   | 所有奇数<tr>标签                                             |
| [:eq(index)](https://codeplayer.vip/p/j7sll)                 | 1.0      | $("li:eq(3)")                 | 第4个li标签(`index`从0开始算起)                              |
| [:gt(index)](https://codeplayer.vip/p/j7slm)                 | 1.0      | $("li:gt(2)")                 | 所有`index`大于2的li标签(第4、5、6……个li标签)                |
| [:lt(index)](https://codeplayer.vip/p/j7sln)                 | 1.0      | $("li:lt(2)")                 | 所有`index`小于2的li标签(第1、2个li标签)                     |
| ==**伪类选择器——根据元素在父元素的子元素中的特定次序筛选元素**== |          |                               |                                                              |
| [:first-child](https://codeplayer.vip/p/j7slr)               | 1.1.4    | $("span:first-child")         | 所有作为父元素的第一个子元素的<span>元素                     |
| [:last-child](https://codeplayer.vip/p/j7sls)                | 1.1.4    | $("span:last-child")          | 所有作为父元素的最后一个子元素的<span>元素                   |
| [:only-child](https://codeplayer.vip/p/j7sm4)                | 1.1.4    | $("span:only-child")          | 所有作为父元素的唯一子元素的<span>元素                       |
| [:nth-child(n)](https://codeplayer.vip/p/j7sm3)              | 1.1.4    | $("li:nth-child(2)")          | 所有作为父元素的第2个子元素的<li>标签(`n`从1开始算起)        |
| [:nth-last-child(n)](https://codeplayer.vip/p/j7smk)         | 1.9      | $("li:nth-last-child(2)")     | 所有作为父元素的倒数第2个子元素的<li>标签                    |
| [:first-of-type](https://codeplayer.vip/p/j7sn0)             | 1.9      | $("p:first-of-type")          | 所有作为父元素的第一个<p>类型的子元素                        |
| [:last-of-type](https://codeplayer.vip/p/j7sn1)              | 1.9      | $("p:last-of-type")           | 所有作为父元素的最后一个<p>类型的子元素                      |
| [:only-of-type](https://codeplayer.vip/p/j7sn4)              | 1.9      | $("p:only-of-type")           | 所有作为父元素的唯一一个<p>类型的子元素                      |
| [:nth-of-type(n)](https://codeplayer.vip/p/j7sn2)            | 1.9      | $("li:nth-of-type(2)")        | 所有作为父元素的第2个<li>类型的子元素(`n`从1开始算起)        |
| [:nth-last-of-type(n)](https://codeplayer.vip/p/j7sn3)       | 1.9      | $("li:nth-last-child(2)")     | 所有作为父元素的倒数第2个<li>类型的子元素                    |
| ==**伪类选择器——根据包含、排除、可见、动画或其他关系筛选元素**== |          |                               |                                                              |
| [:has(selector)](https://codeplayer.vip/p/j7sm0)             | 1.1.4    | $("ul:has(li.abc)")           | 所有包含类名为"abc"的<li>标签的<ul>元素                      |
| [:not(selector)](https://codeplayer.vip/p/j7slk)             | 1.0      | $("input:not(:text)")         | 所有不是文本框的<input>元素                                  |
| [:contains(text)](https://codeplayer.vip/p/j7slv)            | 1.1.4    | $(":contains(abc)")           | 所有包含文本"abc"的元素                                      |
| [:parent](https://codeplayer.vip/p/j7slt)                    | 1.0      | $(":parent")                  | 所有包含子元素或文本内容(哪怕是空格或换行)的元素             |
| [:empty](https://codeplayer.vip/p/j7slu)                     | 1.0      | $(":empty")                   | 所有没有子元素和文本内容(哪怕是空格或换行)的元素             |
| [:visible](https://codeplayer.vip/p/j7sm1)                   | 1.0      | $(":visible")                 | 所有可见的元素                                               |
| [:hidden](https://codeplayer.vip/p/j7sm2)                    | 1.0      | $(":hidden")                  | 所有不可见的元素(包括type="hidden"的<input>元素)             |
| [:header](https://codeplayer.vip/p/j7slq)                    | 1.2      | $(":header")                  | 所有标题标签：h1 ~ h6                                        |
| [:animated](https://codeplayer.vip/p/j7smv)                  | 1.2      | $(":animated")                | 所有正在执行动画效果的元素                                   |
| [:focus](https://codeplayer.vip/p/j7smu)                     | 1.6      | $(":focus")                   | 当前获得焦点的元素                                           |
| [:root](https://codeplayer.vip/p/j7sn5)                      | 1.9      | $(":root")                    | 当前文档的根元素(<html>元素)                                 |
| [:target](https://codeplayer.vip/p/j7sn6)                    | 1.9      | $(":target")                  | id属性等于当前页面URI中的hash码值的元素                      |
| [:lang(language)](https://codeplayer.vip/p/j7sn7)            | 1.9      | $(":lang(en)")                | 所有lang属性以"en"为前缀的元素                               |
| ==**属性相关选择器**==                                       |          |                               |                                                              |
| [[attribute\]](https://codeplayer.vip/p/j7sml)               | 1.0      | $("[href]")                   | 所有带有href属性的元素                                       |
| [[attribute=value\]](https://codeplayer.vip/p/j7smm)         | 1.0      | $("[name=uid]")               | 所有name="uid"的元素                                         |
| [[attribute!=value\]](https://codeplayer.vip/p/j7smn)        | 1.0      | $("[name!=uid]")              | 所有name属性的值不等于"uid"的元素                            |
| [[attribute^=value\]](https://codeplayer.vip/p/j7smo)        | 1.0      | $("[name^=uid]")              | 所有name属性的值以"uid"开头的元素                            |
| [[attribute$=value\]](https://codeplayer.vip/p/j7smp)        | 1.0      | $("[src$='.gif']")            | 所有src属性以".gif"结尾的元素                                |
| [[attribute\|=value\]](https://codeplayer.vip/p/j7sms)       | 1.0      | $("[name\|=uid]")             | name属性的值等于"uid"，或以"uid-"开头的所有元素              |
| [[attribute~=value\]](https://codeplayer.vip/p/j7smt)        | 1.0      | $("[name~='uid']")            | name属性的值包含给定的单词"uid"的所有元素("uid"与其他词以空格分隔) |
| [[attribute*=value\]](https://codeplayer.vip/p/j7smn)        | 1.0      | $("[name*=uid]")              | 所有name属性的值包含"uid"的元素                              |
| ==**伪类选择器——表单相关**==                                 |          |                               |                                                              |
| [:input](https://codeplayer.vip/p/j7sm6)                     | 1.0      | $(":input")                   | 所有input、select、textarea和button标签                      |
| [:text](https://codeplayer.vip/p/j7sm7)                      | 1.0      | $(":text")                    | 所有type="text"的<input>元素                                 |
| [:password](https://codeplayer.vip/p/j7sm8)                  | 1.0      | $(":password")                | 所有type="password"的<input>元素                             |
| [:radio](https://codeplayer.vip/p/j7sm9)                     | 1.0      | $(":radio")                   | 所有type="radio"的<input>元素                                |
| [:checkbox](https://codeplayer.vip/p/j7sma)                  | 1.0      | $(":checkbox")                | 所有type="checkbox"的<input>元素                             |
| [:submit](https://codeplayer.vip/p/j7smb)                    | 1.0      | $(":submit")                  | 所有type="submit"的<input>和<button>元素                     |
| [:reset](https://codeplayer.vip/p/j7smf)                     | 1.0      | $(":reset")                   | 所有type="reset"的<input>元素和<button>元素                  |
| [:button](https://codeplayer.vip/p/j7smd)                    | 1.0      | $(":button")                  | 所有<button>标签(不区分type)和type="button"的<input>元素     |
| [:image](https://codeplayer.vip/p/j7smc)                     | 1.0      | $(":image")                   | 所有type="image"的<input>元素                                |
| [:file](https://codeplayer.vip/p/j7sme)                      | 1.0      | $(":file")                    | 所有type="file"的<input>元素                                 |
| **==伪类选择器——表单状态相关(表单控件是指input、select、textarea、button、option元素)==** |          |                               |                                                              |
| [:enabled](https://codeplayer.vip/p/j7smg)                   | 1.0      | $(":enabled")                 | 所有可用(没有`disabled`属性)的表单控件元素                   |
| [:disabled](https://codeplayer.vip/p/j7smh)                  | 1.0      | $(":disabled")                | 所有禁用(带有`disabled`属性)的表单控件元素                   |
| [:selected](https://codeplayer.vip/p/j7smj)                  | 1.0      | $(":selected")                | 所有被选中的<option>元素                                     |
| [:checked](https://codeplayer.vip/p/j7smi)                   | 1.0      | $(":checked")                 | 所有被选中的radio、checkbox和<option>元素                    |

## 1、.className

jQuery的.className选择器(类选择器)用于==根据css类名`className`获取所有匹配的元素，将其封装为jQuery对象并返回==。

语法

*JavaScript:*

```js
// 这里的className指的是具体的css类名
jQuery( ".className" )
```

参数

| 参数      | 描述                      |
| :-------- | :------------------------ |
| className | String类型指定的css类名。 |

**返回值**

返回封装了带有指定css类名的所有DOM元素的jQuery对象。

如果一个元素包含多个类，只要其中有一个类符合就可以被匹配到。

由于多个标签可以有相同的css类名，因此返回的jQuery中可能封装了多个DOM元素。如果找不到对应类名的DOM元素，则返回一个空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<p id="n2" class="test"></p>
	<p id="n3" class="detail">
		<span id="n4" class="test codeplayer"></span>
	</p>
</div>
```

现在，我们想要查找css类名为test的DOM元素，则可以编写jQuery代码：

*JavaScript:*

```js
// 选择了id为n2、n4的两个元素
// span标签有两个类名，只要其中有一个为test即可匹配到
$(".test");
```

如果要查找css类名为detail的DOM元素，对应的jQuery代码如下：

*JavaScript:*

```js
// 选择了id为n3的一个元素
$(".detail");
```

## 2、tagName

jQuery的tagName选择器(标签选择器)用于==匹配所有HTML标签名为`tagName`的元素，将其封装为jQuery对象并返回==。

该选择器的作用，类似于`document.getElementsByTagName(tagName)`，只不过一个是返回DOM元素的数组，一个是返回封装了该DOM元素数组的jQuery对象。

语法

*JavaScript:*

```js
// 这里的tagName指的是具体的标签名
jQuery( "tagName" )
```

参数

| 参数    | 描述             |
| :------ | :--------------- |
| tagName | 指定的标签名称。 |

标签名称不区分大小写。

**返回值**

返回封装了指定标签名称的DOM元素的jQuery对象。

由于一个文档中可以存在多个同名的标签，因此返回的jQuery对象内部可能封装了多个DOM元素。如果找不到对应标签名的DOM元素，则返回一个空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="myDiv">
	<p id="java"></p>
	<p id="php">
		<span id="abc.func"></span>
	</p>
</div>
```

现在，我们想要查找所有的p标签DOM元素，其jQuery代码如下：

*JavaScript:*

```js
// 选择了id为java、php的两个元素
$("p");
// 标签名称不区分大小写，下面这种方式也是可以的，不过建议统一为小写形式
// $("P");
```

如果要查找所有的div标签DOM元素，其jQuery代码如下：

*JavaScript:*

```js
// 选择了id为myDiv的一个元素
$("div");
```

## 3、#id

jQuery的#id选择器(ID选择器)用于==根据id属性值获取对应的元素(最多一个元素)，将其封装为jQuery对象并返回==。

该选择器的作用，类似于`document.getElementById(id)`，只不过一个是返回DOM元素，一个是返回封装了该DOM元素的jQuery对象。

语法

*JavaScript:*

```js
// 这里的id指的是具体的id属性值
jQuery( "#id" )
```

参数

| 参数 | 描述                       |
| :--- | :------------------------- |
| id   | String类型指定的id属性值。 |

如果id属性值中包含特殊字符，你需要使用两个反斜杠(\)对其进行转义。

**返回值**

返回封装了指定id的DOM元素的jQuery对象。

如果有多个相同的id值，则以**第一个**id为准(HTML规范要求每个DOM元素的id值必须是唯一的，如果存在相同的id，这本身就不符合规范)。如果找不到对应id的DOM元素，则返回一个空的jQuery对象。

因此，jQuery通过id选择器最多只能选择一个DOM元素。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="myDiv">
	<p id="java"></p>
	<p id="php">
		<span id="abc.func"></span>
	</p>
</div>
```

现在，我们想要查找id为java的DOM元素，将其文本内容改为<b>java</b>：

*JavaScript:*

```js
// 选择了id为java的元素，并改变其innerHTML
$("#java").html('<b>java</b>');
```

如果要查找id为abc.func的DOM元素，由于该id属性值中包含特殊字符.，因此我们需要对其进行转义：

*JavaScript:*

```js
// 选择了id为abc.func的元素
$("#abc\\.func");
```

## 4、parent > child

jQuery的parent > child选择器(子代选择器)用于==匹配`parent`元素的所有**子辈**`child`元素，将其封装为jQuery对象并返回==。

*注意*：选择器`child`的查找范围必须是"parent元素"的**子辈元素**，**不包括**"孙子辈"及更后辈的元素。
如果你想在所有的后代元素中查找，请使用[后代选择器(ancestor descendant)](https://codeplayer.vip/p/j7sle)。

语法

*JavaScript:*

```js
// 这里的parent表示具体的父辈选择器
// 这里的child表示具体的子辈选择器
jQuery( "parent > child" )
```

\>号两侧的空格可以省略，但不建议省略，否则字符过于紧密可能影响阅读。

参数

| 参数   | 描述                                               |
| :----- | :------------------------------------------------- |
| parent | 一个有效的父辈选择器。                             |
| child  | 一个有效的子辈选择器，只用于匹配父辈选择器的子元素 |

**返回值**

返回封装了在父辈元素内查找到的符合条件的子元素的jQuery对象。

如果找不到与父辈选择器匹配的DOM元素，或者在符合父辈选择器的DOM元素内找不到符合子代选择器的子元素，则返回一个空的jQuery对象。

符合父辈选择器的父辈DOM元素可能有多个，在一个父辈DOM元素内也可能查找到多个子DOM元素，返回的jQuery对象中封装了符合条件的所有DOM元素。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<p id="n2" class="test">
		<span id="n3" class="a">Hello</span>
	</p>
	<p id="n4" class="detail">
		<span id="n5" class="b codeplayer">World
			<span id="n6" class="c">365mini.com</span>
		</span>
	</p>
</div>
```

现在，我们想要一次性查找到p标签内所有的span子元素，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id分别为n3、n5的两个元素
// n6不是p标签的子元素，而是孙子辈的元素，因此无法匹配
$("p > span");
```

接着，我们查找span标签的span子元素，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id为n6的一个元素
$("span > span");
```

我们可以配合使用[所有元素选择器(*)](https://codeplayer.vip/p/j7slc)来实现只查找**孙子辈元素**的选择器。例如：我们想要查找id为n1的元素的孙子辈的span标签，对应的jQuery代码如下：

*JavaScript:*

```js
// 选择了id分别为n3、n5的两个元素
$("#n1 > * > span");
```

## 5、:first

jQuery的:first选择器用于==**获取匹配到的第一个元素**，将其封装为jQuery对象并返回==。:first选择器等价于[:eq(0)选择器](https://codeplayer.vip/p/j7sll)。

与:first选择器相对的是[:last选择器](https://codeplayer.vip/p/j7slj)，用于获取匹配到的最后一个元素。

*注意*：:first选择器与[:first-child选择器](https://codeplayer.vip/p/j7slr)的不同之处在于：
:first选择器只匹配一个元素，并且是匹配到的第一个元素；
:first-child选择器则需要判断匹配到的元素是否是其父元素的第一个子元素，如果是就保留，否则将被舍弃。

语法

复制

全屏

全选

*JavaScript:*

```js
// 这里的selector表示具体的选择器
jQuery( "selector:first" )
```

参数

| 参数     | 描述               |
| :------- | :----------------- |
| selector | 一个有效的选择器。 |

**返回值**

返回封装了匹配选择器`selector`的第一个元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>
	<div id="n7">
		<ul id="n8">
			<li id="n9">item1</li>
			<li id="n10">item2</li>
		</ul>
	</div>
</div>
```

现在，我们想要查找第一个div标签，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id为n1的一个元素
$("div:first");
```

接着，查找所有ul标签中的第一个li标签，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id为n4的一个元素
// 虽然HTML中有两个ul标签，但:first不是分别取每个ul中的第一个li，而是从上到下只要找到一个符合条件的元素就立即返回
$("ul li:first");
```

## 6、:eq(index)

jQuery的:eq(index)选择器用于==**获取匹配的元素中指定索引的元素**，将其封装为jQuery对象并返回==。

*注意*：eq(index)选择器与[:nth-child(n)选择器](https://codeplayer.vip/p/j7sm3)的不同之处在于：

:eq(index)选择器只匹配一个元素，并且是所有匹配到的元素中的第`index + 1`个元素(索引`index`从0开始算起)；

:nth-child(n)选择器则需要判断匹配到的元素是否是其父元素的第`n`个子元素或符合特定要求(序号`n`从1开始算起)，如果是就保留，否则将被舍弃。

语法

*JavaScript:*

```js
// 这里的selector表示具体的选择器
// 这里的index表示指定的索引值
jQuery( "selector:eq(index)" )
```

参数

| 参数     | 描述                        |
| :------- | :-------------------------- |
| selector | 一个有效的选择器。          |
| index    | 指定的索引值，从0开始计数。 |

1.8 新增支持参数`index`可以为负数。如果`index`为负数，则将其视作`length + index`，这里的`length`指的是匹配到的元素的个数(也可以理解为从后往前计数)。

**返回值**

返回封装了匹配选择器`selector`的DOM元素中指定索引`index`处的元素的jQuery对象。

如果索引值超出有效范围，则返回空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>
	<div id="n7">
		<ul id="n8">
			<li id="n9">item1</li>
			<li id="n10">item2</li>
		</ul>
	</div>
</div>
```

现在，我们想要查找第2个div标签，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id为n2的一个元素
$("div:eq(1)");
```

接着，获取匹配ul li选择器的元素中的第4个元素，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id为n9的一个元素
$("ul li:eq(3)");
```

## 7、:first-child

jQuery的:first-child选择器用于==**匹配作为父元素的第一个子元素的元素**，将其封装为jQuery对象并返回==。:first-child选择器等价于[:nth-child(1)选择器](https://codeplayer.vip/p/j7sm3)。

与该选择器相对的是[:last-child选择器](https://codeplayer.vip/p/j7sls)，用于匹配作为父元素的最后一个子元素的元素。

*注意*：:first-child选择器与[:first选择器](https://codeplayer.vip/p/j7sli)的不同之处在于：
:first选择器只匹配一个元素，并且是匹配到的元素中的第一个元素；
:first-child选择器则需要判断匹配到的元素是否是其父元素的第一个子元素，如果是就保留，否则将被舍弃。

语法

jQuery1.1.4 新增该选择器。

*JavaScript:*

```js
// 这里的selector表示具体的选择器
jQuery( "selector:first-child" )
```

参数

| 参数     | 描述               |
| :------- | :----------------- |
| selector | 一个有效的选择器。 |

**返回值**

返回封装了匹配作为父元素的第一个子元素的元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

jQuery先会根据选择器`selector`去查找所有匹配的元素，再判断它们是否是自己父元素的"长子"(第一个子元素)，如果是就保留，否则就舍弃掉该元素。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
    CodePlayer
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5" class="c">item2</li>
			<li id="n6" class="c">item3</li>
		</ul>
	</div>
	<div id="n7">
		<ul id="n8">
			<li id="n9">item1</li>
			<li id="n10">item2</li>
		</ul>
	</div>
</div>
```

现在，我们查找作为父元素的"长子"的div标签，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id分别为n1、n2的两个元素
// n1是父元素body标签的"长子"，n2是父元素n1的"长子"
// 虽然在n1之内、n2之前有文本内容，但文本内容不算子元素，因此n2仍然是n1的"长子"
$("div:first-child");
```

接着，查找所有匹配ul li的元素，再查找其中那些元素是父元素的"长子"，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id分别为n4、n9的两个元素
$("ul li:first-child");
```

查找所有包含类名c的li标签，再查找这些元素是否是父元素的"长子"，对应的jQuery代码如下：

*JavaScript:*

```js
// 没有选择任何元素，返回一个空的jQuery对象。
// 虽然包含类名"c"的li标签有n5、n6两个元素，但它们都不是父元素的"长子"，因此无法匹配
$("li.c:first-child");
```

## 8、:nth-child(n)

jQuery的:nth-child(n)选择器用于==**匹配作为父元素下的第n个(或特定顺序的)\**子元素的\**元素**，将其封装为jQuery对象并返回==。

与该选择器**相对**的是[:nth-last-child(n)选择器](https://codeplayer.vip/p/j7smk)，用于匹配作为父元素下的**倒数**第n个(或符合特定倒数顺序的)子元素。

*注意*：:nth-child(n)选择器与[:eq(index)选择器](https://codeplayer.vip/p/j7sll)的不同之处在于：
:eq(index)选择器只匹配一个元素，并且是所有匹配到的元素中的第`index + 1`个元素(索引`index`从0开始算起)；
:nth-child(n)选择器则需要判断匹配到的元素是否是其父元素的第`n`个子元素或符合其他特定要求(序号`n`从1开始算起)，如果是就保留，否则将被舍弃。

语法

jQuery1.1.4 新增该选择器。

*JavaScript:*

```js
// 这里的selector表示具体的选择器
// 这里的n表示具体的序号或者符合要求的表达式
jQuery( "selector:nth-child(n)" )
```

参数

| 参数     | 描述                      |
| :------- | :------------------------ |
| selector | 一个有效的选择器。        |
| n        | 指定的序号，从1开始计数。 |

参数`n`一般是一个自然数，表示作为父元素下的第`n`个子元素。例如：:nth-child(2)表示作为父元素的第2个子元素。

参数`n`也可以为特定的表达式(表达式中只能使用字母n表示自然数，大小写均可)。例如:

- :nth-child(odd)表示匹配作为父元素的奇数(第1、3、5、7……个)子元素的元素；
- :nth-child(even)表示匹配作为父元素的偶数(第2、4、6、8……个)子元素的元素；
- :nth-child(3n)表示匹配作为父元素的第`3n`个子元素的元素(n表示包括0在内的自然数，下同)；
- :nth-child(3n+1)表示匹配作为父元素的第`3n+1`个子元素的元素；
- :nth-child(3n+2)表示匹配作为父元素的第`3n+2`个子元素的元素；

**返回值**

返回封装了匹配到的元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

jQuery先会根据选择器`selector`去查找所有匹配的元素，再看它们是否是父元素的符合指定顺序的子元素，如果是就保留，否则舍弃掉该元素。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4" class="c">item1</li>
			<li id="n5">item2</li>
			<li id="n6" class="c">item3</li>
		</ul>
	</div>
	<div id="n7">
		<ul id="n8">
			<li id="n9">item1</li>
			<li id="n10">item2</li>
		</ul>
	</div>
</div>
```

现在，我们想要为每个ul标签内查找它的第2个li标签，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id分别为n5、n10的两个元素
$("ul li:nth-child(2)");
```

接着，为每个ul标签查找自然顺序为奇数的li标签，则可以编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id分别为n4、n6、n9的3个元素
$("ul li:nth-child(odd)");
```

为每个ul父标签查找自然顺序为`3n`的li标签，对应的jQuery代码如下：

*JavaScript:*

```js
// 选择了id为n6的一个元素
// 虽然这里用的#n1进行限定，实际上jQuery先是通过查找所有匹配#n1 li的元素，然后再看这些元素是不是父元素的第3n个元素，如果是就保留，否则就舍弃掉。
$("#n1 li:nth-child(3n)");
```

查找所有包含类名c的li标签，并且它们必须是父元素的偶数顺序的子元素，我们可以编写如下jQuery代码：

*JavaScript:*

```js
// 没有选择任何元素，返回空的jQuery对象
// 虽然匹配li.c的有n4、n6两个元素，但它们都不是父元素的偶数顺序的子元素，因此无法匹配
$("li.c:nth-child(even)");
```

## 9、:disabled

jQuery的:disabled选择器用于==**匹配所有不可用的表单控件元素**，将其封装为jQuery对象并返回==。

不可用的表单控件是指带有`disabled`属性的<input>、<button>、<select>、<textarea>、<option>等元素。

与该选择器**相对**的是[:enable选择器](https://codeplayer.vip/p/j7smg)，用于匹配所有可用的表单控件元素。

语法

*JavaScript:*

```js
jQuery( ":disabled" )
```

**返回值**

返回封装了所有不可用元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<form id="n2">
		<label id="n3">CodePlayer</label>
		<input id="n4" type="text" disabled="disabled" >
	   <input id="n5" type="checkbox" />
	   <input id="n6" type="password" />
	   <button id="n7" type="button" disabled="disabled">Button</button>
	   <select id="n8">
	   	<option id="n9">item1</option>
	   	<option id="n10" disabled="disabled">item2</option>
	   </select>
	</form>
</div>
```

现在，我们查找所有的不可用元素，即可编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id分别为n4、n7、n10的3个元素
$(":disabled");
```

## 10、:checked

jQuery的:checked选择器用于==**匹配所有选中的表单域元素**，将其封装为jQuery对象并返回==。

选中的表单域是指具有`checked`属性的radio和checkbox表单域，以及具有`selected`属性的option标签。

*注意*：:checked选择器不仅匹配具有`checked`属性的radio和checkbox，还可以匹配具有`selected`属性的option标签。网上有些文章说，:checked选择器只匹配具有`checked`属性的radio和checkbox是**错误**的。详情参见jQuery官方文档[:checked Selector](http://api.jquery.com/checked-selector/)。

语法

*JavaScript:*

```js
jQuery( ":checked" )
```

**返回值**

返回封装了所有选中的表单域元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<form id="n2">
		<label id="n3">CodePlayer</label>
		<input id="n4" type="text" disabled="disabled" >
	   <input id="n5" type="checkbox" checked="checked" />
	   <input id="n6" type="checkbox" />
	   <input id="n7" type="radio" checked="checked" />	    
	   <input id="n8" type="radio" />	    
	   <button id="n9" type="button" disabled="disabled">Button</button>
	   <select id="n10">
	   	<option id="n11" selected="selected">item1</option>
	   	<option id="n12">item2</option>
	   </select>
	</form>
</div>
```

现在，我们查找所有的提交按钮，即可编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id分别为n5、n7、n11的3个元素
// :checked可以匹配"selected"的option
$(":checked");
```

如果你只希望匹配选中的radio和checkbox，请使用input:checked。

*JavaScript:*

```js
// 选择了id分别为n5、n7的两个元素
$("input:checked");
```

如果你只希望匹配选中的checkbox，请使用:checkbox:checked。radio也是同理。

*JavaScript:*

```js
// 选择了id为n5的一个元素
$(":checkbox:checked");
```

## 11、:selected

jQuery的:selected选择器用于**匹配所有选中的option元素**，将其封装为jQuery对象并返回。

选中的option元素指的是具有`selected`属性的option标签。

语法

*JavaScript:*

```js
jQuery( ":selected" )
```

**返回值**

返回封装了所有选中的option元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
    <form id="n2">
        <label id="n3">CodePlayer</label>
        <input id="n4" type="text" disabled="disabled" >
        <input id="n5" type="checkbox" checked="checked" />
        <input id="n6" type="checkbox" />
        <input id="n7" type="radio" checked="checked" />	    
        <input id="n8" type="radio" />	    
        <button id="n9" type="button" disabled="disabled">Button</button>
        <select id="n10">
            <option id="n11" selected="selected">item1</option>
            <option id="n12">item2</option>
        </select>
    </form>
</div>
```

现在，我们查找所有选中的option元素，即可编写如下jQuery代码：

*JavaScript:*

```js
// 选择了id为n11的一个元素
$(":selected");
```

# 三、文档筛选

## 0、jQuery对象的文档筛选方法

> *重要说明*：如果"版本"列的版本号带有删除线(例如： ~~1.8~~)，表示从该版本开始，此方法 **已过时**。如果版本号带有删除线，并且为红色(例如： ~~1.9~~)，表示从该版本开始，此方法已 **被移除**。

| 方法                                                         | 初始版本    | 描述                                                         |
| :----------------------------------------------------------- | :---------- | :----------------------------------------------------------- |
| ==判断方法——判断当前匹配元素中是否有符合条件的元素==         |             |                                                              |
| [hasClass()](https://codeplayer.vip/p/j7sns)                 | 1.2         | 判断是否有包含指定CSS类名的元素。                            |
| [is()](https://codeplayer.vip/p/j7so3)                       | 1.0         | 判断是否有符合条件的元素。                                   |
| ==过滤方法——在当前匹配元素中筛选符合条件的元素==             |             |                                                              |
| [eq()](https://codeplayer.vip/p/j7so0)                       | 1.1.2       | 返回指定索引的元素。                                         |
| [filter()](https://codeplayer.vip/p/j7so7)                   | 1.0         | 筛选符合条件的元素。                                         |
| [first()](https://codeplayer.vip/p/j7so1)                    | 1.4         | 返回匹配的第一个元素。                                       |
| [has()](https://codeplayer.vip/p/j7so5)                      | 1.4         | 筛选包含特定后代元素的元素。                                 |
| [last()](https://codeplayer.vip/p/j7so2)                     | 1.4         | 返回匹配的最后一个元素。                                     |
| [map()](https://codeplayer.vip/p/j7so4)                      | 1.2         | 使用函数处理每个匹配元素，并返回表示处理结果的jQuery对象。   |
| [not()](https://codeplayer.vip/p/j7so6)                      | 1.0         | 排除掉其中符合指定条件的元素。                               |
| [slice()](https://codeplayer.vip/p/j7so8)                    | 1.1.4       | 选取其中连续的一部分元素。                                   |
| ==查找方法——根据与当前匹配元素的关系查找符合指定条件的元素== |             |                                                              |
| [children()](https://codeplayer.vip/p/j7so9)                 | 1.0         | 查找符合条件的子元素。                                       |
| [contents()](https://codeplayer.vip/p/j7sop)                 | 1.2         | 查找所有子节点(包括文本节点、注释节点等)。                   |
| [end()](https://codeplayer.vip/p/j7soq)                      | 1.0         | 返回先前匹配的元素。                                         |
| [find()](https://codeplayer.vip/p/j7soa)                     | 1.0         | 查找符合条件的后代元素。                                     |
| [next()](https://codeplayer.vip/p/j7sob)                     | 1.0         | 查找当前元素之后紧邻的符合条件的同辈元素。                   |
| [nextAll()](https://codeplayer.vip/p/j7soc)                  | 1.2         | 查找当前元素之后的符合条件的所有同辈元素。                   |
| [nextUntil()](https://codeplayer.vip/p/j7sod)                | 1.4         | 查找当前元素之后的符合条件的所有同辈元素，直到遇到满足特定条件的元素为止。 |
| [parent()](https://codeplayer.vip/p/j7soe)                   | 1.0         | 查找符合条件的父元素。                                       |
| [parents()](https://codeplayer.vip/p/j7sof)                  | 1.0         | 查找符合条件的祖辈元素。                                     |
| [parentsUntil()](https://codeplayer.vip/p/j7sog)             | 1.4         | 查找符合条件的祖辈元素，直到遇到满足特定条件的元素为止。     |
| [closest()](https://codeplayer.vip/p/j7soo)                  | 1.3         | 查找符合条件的最近的祖辈元素。                               |
| [offsetParent()](https://codeplayer.vip/p/j7st1)             | 1.2.6       | 查找最近的被定位的祖辈元素。                                 |
| [prev()](https://codeplayer.vip/p/j7soh)                     | 1.0         | 查找当前元素之前紧邻的符合条件的同辈元素。                   |
| [prevAll()](https://codeplayer.vip/p/j7soi)                  | 1.2         | 查找当前元素之前的符合条件的所有同辈元素。                   |
| [prevUntil()](https://codeplayer.vip/p/j7soj)                | 1.4         | 查找当前元素之前的符合条件的所有同辈元素，直到遇到满足特定条件的元素为止。 |
| [siblings()](https://codeplayer.vip/p/j7sok)                 | 1.0         | 查找当前元素符合条件的所有同辈元素。                         |
| ==添加方法——与当前匹配元素的基础上添加(追加)新的元素==       |             |                                                              |
| [add()](https://codeplayer.vip/p/j7som)                      | 1.0         | 添加符合条件的元素。                                         |
| [addBack()](https://codeplayer.vip/p/j7son)                  | 1.8         | 添加先前匹配的元素。                                         |
| [andSelf()](https://codeplayer.vip/p/j7sol)                  | 1.2~~~1.8~~ | 请使用`addBack()`方法替代。                                  |

## 1、jQuery.hasClass() 函数

`hasClass()`函数用于**指示当前jQuery对象所匹配的元素是否含有指定的css类名**。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.hasClass( className )
```

参数

| 参数      | 描述                      |
| :-------- | :------------------------ |
| className | String类型指定的css类名。 |

**返回值**

`hasClass()`函数的**返回值**是Boolean类型，返回表示是否包含指定css类名的boolean值，如果包含就返回`true`，否则返回`false`。

如果当前jQuery对象匹配多个元素，只要其中有**任意一个元素**含有指定的css类名，就返回`true`。

示例&说明

`hasClass(className)`函数等价于`is(".className")`：

*JavaScript:*

```js
$element.hasClass( className );
// 等价于
$element.is( "." + className );
```

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
   	<p id="n2" class="site-name">CodePlayer</p>
   	<p id="n3" class="foo bar demo">专注于编程开发技术分享</p>
</div>
```

我们编写如下jQuery代码来演示`hasClass()`函数的使用：

*JavaScript:*

```js
var $n2 = $("#n2");
document.writeln( $n2.hasClass("site-name") ); // true

var $n3 = $("#n3");
document.writeln( $n3.hasClass("bar") ); // true
// 不存在该css类名，返回false
document.writeln( $n3.hasClass("noClass") ); // false

var $p = $("p");
// 只要jQuery对象匹配的元素中有任意一个元素包含指定的css类名，即返回true
document.writeln( $p.hasClass("site-name") ); // true
document.writeln( $p.hasClass("foo") ); // true
```

## 2、jQuery.eq() 函数

`eq()`函数用于==**获取当前jQuery对象所匹配的元素中指定索引的元素**，并返回封装该元素的jQuery对象==。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.eq( index )
```

参数

| 参数  | 描述                                  |
| :---- | :------------------------------------ |
| index | Number类型指定的索引值，从0开始计数。 |

jQuery 1.4 新增支持：参数`index`可以为负数。如果`index`为负数，则将其视作`length + index`，这里的`length`指的是匹配到的元素的个数(负数的`index`也可理解为从后往前计数)。

**返回值**

`eq()`函数的**返回值**为jQuery类型，返回封装了指定索引`index`处的元素的jQuery对象。

如果索引值超出有效范围，则返回空的jQuery对象。

示例&说明

`eq()`函数与[:eq()](https://codeplayer.vip/p/j7sll)选择器具有如下等价代码：

*JavaScript:*

```js
$( "selector" ).eq( index );
//等价于
$( "selector:eq(index)" );
```

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<div id="n2">
		<ul id="n3">
			<li id="n4">item1</li>
			<li id="n5">item2</li>
			<li id="n6">item3</li>
		</ul>
	</div>
	<div id="n7">
		<ul id="n8">
			<li id="n9">item1</li>
			<li id="n10">item2</li>
		</ul>
	</div>
</div>
```

以下jQuery示例代码用于演示`eq()`函数的具体用法：

*JavaScript:*

```js
// 匹配n4、n5、n6、n9、n10这5个元素
var $li = $("li");

// 获取匹配到的第2个元素，即n5
var $n5 = $li.eq(1);
document.writeln( $n5.attr("id") ); // n5

// 获取匹配到的第4个元素，即n9
var $n9 = $li.eq(3);
document.writeln( $n9.attr("id") ); // n9

// 获取匹配到的第-3个元素，即n6
var $n6 = $li.eq(-3);
document.writeln( $n6.attr("id") ); // n6
```

## 3、jQuery.find() 函数

`find()`函数用于==**选取每个匹配元素的符合指定表达式的后代元素**，并以jQuery对象的形式返回==。

这里的表达式包括：选择器(字符串)、DOM元素(Element)、jQuery对象。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.find( expr )
```

参数

| 参数 | 描述                                    |
| :--- | :-------------------------------------- |
| expr | String/Element/jQuery类型指定的表达式。 |

`find()`函数将在当前jQuery对象每个匹配元素的所有**后代元素**中筛选符合指定表达式的元素。

如果`expr`参数为字符串，则将其视作jQuery选择器，用以表示该选择器所匹配的元素。

jQuery 1.6 新增支持：参数`expr`可以为DOM元素(Element)或jQuery对象。

**返回值**

`find()`函数的**返回值**为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象匹配元素的所有符合指定选择器的**后代元素**。

如果没有匹配的元素，则返回空的jQuery对象。

示例&说明

`find()`函数具有以下等价代码：

*JavaScript:*

```js
// 这里的是selector、selector1均表示任意的选择器
$("selector").find("selector1");
// 等价于
$("selector selector1");
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="e1">
	<span id="e2" class="site">
		<span id="e3" class="item site-name">CodePlayer</span>
		<span id="e4" class="item site-desc">专注于编程开发技术分享</span>
	</span>
	<span id="e5" class="site-url">https://codeplayer.vip</span>
</p>
<p id="e6">
	JavaScript<span id="e7" class="highlight">jQuery</span>
	<a id="e8" href="https://codeplayer.vip">CodePlayer</a>
</p>
```

以下jQuery示例代码用于演示`find()`函数的具体用法：

*JavaScript:*

```js
// 返回jQuery对象所有匹配元素的标识信息数组
// 每个元素形如：tagName或tagName#id(如果有id的话)
function getTagsInfo($doms){
	return $doms.map(function(){
		return this.tagName + (this.id ? "#" + this.id : "");
	}).get();
}

// 匹配id为e1的元素
var $e1 = $("#e1");
var $e1_span = $e1.find("span");
document.writeln( getTagsInfo( $e1_span ) ); // SPAN#e2,SPAN#e3,SPAN#e4,SPAN#e5

var $p = $("p");
var $p_span = $p.find("span");
document.writeln( getTagsInfo( $p_span ) ); // SPAN#e2,SPAN#e3,SPAN#e4,SPAN#e5,SPAN#e7

var $highlight = $p.find( $(".highlight") );
document.writeln( getTagsInfo( $highlight ) ); // SPAN#e7

var a = document.getElementsByTagName("a");
var $a = $p.find( a );
document.writeln( getTagsInfo( $a ) ); // A#e8
```

## 4、jQuery.next() 函数

`next()`函数用于==**筛选每个匹配元素之后紧邻的同辈元素**，并以jQuery对象的形式返回==。

你还可以使用指定的选择器进一步缩小筛选范围，筛选出符合指定选择器的元素。

与该函数**相对**的是[prev()](https://codeplayer.vip/p/j7soh)函数，用于筛选每个匹配元素之前紧邻的同辈元素。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.next( [ selector ] )
```

参数

| 参数     | 描述                                |
| :------- | :---------------------------------- |
| selector | 可选/String类型指定的选择器字符串。 |

`next()`函数将在当前jQuery对象每个匹配元素的**下一个****相邻**的**同辈**元素中筛选**符合指定选择器**的元素。

如果省略`selector`参数，则选取每个匹配元素的下一个相邻的同辈元素。

**返回值**

`next()`函数的**返回值**为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象所有匹配元素的下一个紧邻的符合指定选择器的同辈元素。

如果没有符合条件的元素，则返回空的jQuery对象。

示例&说明

`next()`函数与[prev + next](https://codeplayer.vip/p/j7slg)选择器具有以下等价代码：

*JavaScript:*

```js
// 这里的selector、selector1均表示任意的选择器
$("selector").next("selector1");
// 等价于
$("selector + selector1");


$("selector").next( );
// 等价于
$("selector + *");
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="e1">
	<span id="e2" class="site">
		<span id="e3" class="item site-name">CodePlayer</span>
		<span id="e4" class="item site-desc">专注于编程开发技术分享</span>
	</span>
	<span id="e5" class="site-url">https://codeplayer.vip</span>
</p>
<p id="e6">
	JavaScript<span id="e7" class="highlight">jQuery</span>
	<a id="e8" href="https://codeplayer.vip">CodePlayer</a>
	<span id="e9" class="highlight">PHP</span>
</p>
```

以下jQuery示例代码用于演示`next()`函数的具体用法：

*JavaScript:*

```js
// 返回jQuery对象所有匹配元素的标识信息数组
// 每个元素形如：tagName或tagName#id(如果有id的话)
function getTagsInfo($doms){
	return $doms.map(function(){
		return this.tagName + (this.id ? "#" + this.id : "");
	}).get();
}

// 匹配所有span元素：e2、e3、e4、e5、e7、e9
var $span = $("span");
// 匹配所有span元素之后紧邻的同辈元素：e5、e4、e8
// e2的下一个紧邻的同辈元素是e5
// e3的是e4
// e4没有(因为它是同辈元素中的最后一个，下同)
// e5没有
// e7的是e8
// e9没有
var $span_next = $span.next( );
document.writeln( getTagsInfo( $span_next ) ); // SPAN#e5,SPAN#e4,A#e8

// 匹配所有span元素之后紧邻的同辈span元素
var $span_next_span = $span.next( "span" );
document.writeln( getTagsInfo( $span_next_span ) ); // SPAN#e5,SPAN#e4
```

## 5、jQuery.prev() 函数

`prev()`函数用于==**筛选每个匹配元素之前紧邻的同辈元素**，并以jQuery对象的形式返回==。

你还可以使用指定的选择器进一步缩小筛选范围，筛选出符合指定选择器的元素。

与该函数**相对**的是[next()](https://codeplayer.vip/p/j7sob)函数，用于筛选每个匹配元素之后紧邻的同辈元素。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.prev( [ selector ] )
```

参数

| 参数     | 描述                                |
| :------- | :---------------------------------- |
| selector | 可选/String类型指定的选择器字符串。 |

`prev()`函数将在当前jQuery对象每个匹配元素的**上一个****相邻**的**同辈**元素中筛选**符合指定选择器**的元素。

如果省略`selector`参数，则选取每个匹配元素的上一个相邻的同辈元素。

**返回值**

`prev()`函数的**返回值**为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象所有匹配元素的上一个紧邻的符合指定选择器的同辈元素。

如果没有符合条件的元素，则返回空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<p id="e1">
	<span id="e2" class="site">
		<span id="e3" class="item site-name">CodePlayer</span>
		<span id="e4" class="item site-desc">专注于编程开发技术分享</span>
	</span>
	<span id="e5" class="site-url">https://codeplayer.vip</span>
</p>
<p id="e6">
	JavaScript<span id="e7" class="highlight">jQuery</span>
	<a id="e8" href="https://codeplayer.vip">CodePlayer</a>
	<span id="e9" class="highlight">PHP</span>
</p>
```

以下jQuery示例代码用于演示`prev()`函数的具体用法：

*JavaScript:*

```js
// 返回jQuery对象所有匹配元素的标识信息数组
// 每个元素形如：tagName或tagName#id(如果有id的话)
function getTagsInfo($doms){
	return $doms.map(function(){
		return this.tagName + (this.id ? "#" + this.id : "");
	}).get();
}

//匹配所有span元素：e2、e3、e4、e5、e7、e9
var $span = $("span");

//匹配所有span元素之前紧邻的同辈元素：e3、e2、e8
//e2 => 无【没有上一个紧邻的同辈元素，因为它是同辈元素中的第一个，下同】
//e3 => 无
//e4 => e3
//e5 => e2
//e7 => 无
//e9 => e8
var $span_prev = $span.prev( );
document.writeln( getTagsInfo( $span_prev ) ); // SPAN#e3,SPAN#e2,A#e8

//匹配所有span元素之前紧邻的同辈span元素
var $span_prev_span = $span.prev( "span" );
document.writeln( getTagsInfo( $span_prev_span ) ); // SPAN#e3,SPAN#e2
```

## 6、jQuery.siblings() 函数

`siblings()`函数用于==**选取每个匹配元素的所有同辈元素(不包括自己)**，并以jQuery对象的形式返回==。

你还可以使用选择器来进一步缩小选取范围，筛选出符合指定选择器的元素。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.siblings( [ selector ] )
```

参数

| 参数     | 描述                                |
| :------- | :---------------------------------- |
| selector | 可选/String类型指定的选择器字符串。 |

`siblings()`函数将在当前jQuery对象每个匹配元素的所有**同辈元素**中筛选**符合指定选择器**的元素。

如果省略`selector`参数，则选取每个匹配元素的所有同辈元素。

**返回值**

`siblings()`函数的**返回值**为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象每个匹配元素的所有符合指定选择器的同辈元素。

如果没有符合条件的元素，则返回空的jQuery对象。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<span id="n2">
		<span id="n3">A</span>
	</span>
	<label id="n4">B</label>
	<span id="n5">
		<span id="n6">C</span>
	</span>
	<strong id="n7" class="active">D</strong>
	<span id="n8" class="active">E</span>
</p>
<p id="n9">
	<span id="n10"></span>
	<label id="n11"></label>
	<span id="n12" class="active"></span>
</p>
```

以下jQuery示例代码用于演示`siblings()`函数的具体用法：

*JavaScript:*

```js
//返回jQuery对象所有匹配元素的标识信息数组
//每个元素形如：#id
function getTagsInfo($doms){
	return $doms.map(function(){
		return "#" + this.id;
	}).get();
}

var $n4 = $("#n4");

//匹配n4的所有同辈元素(同辈元素不会包括n4自己，下同)
var $elements = $n4.siblings( );
document.writeln( getTagsInfo( $elements ) ); // #n2,#n5,#n7,#n8

//匹配n4所有的同辈span元素
var $matches = $n4.siblings("span");
document.writeln( getTagsInfo( $matches ) ); // #n2,#n5,#n8

var $label = $("label");
//匹配所有label元素的含有类名"active"的同辈元素
var $actives = $label.siblings(".active");
document.writeln( getTagsInfo( $actives ) ); // #n7,#n8,#n12
```

# 四、属性

## 0、jQuery对象的文档操作方法

> *版本说明*：如果"版本"列的版本号带有删除线(例如： ~~1.8~~)，表示从该版本开始，此方法 **已过时**。如果版本号带有删除线，并且为红色(例如： ~~1.9~~)，表示从该版本开始，此方法已 **被移除**。

*注意*：
如果当前jQuery对象匹配多个DOM元素，那么我们执行该对象的下列方法时：如果当前执行的是"写"操作，则作用于每一个匹配的元素；如果当前执行的是"读"操作，则只作用于第一个匹配的元素。
以使用`attr()`方法为例：如果我们用它来设置属性，它将会为匹配的每一个元素都设置属性；如果用它来读取属性，则它只会获取第一个匹配元素对应的属性值。

如果当前jQuery对象不匹配任何元素，执行以下方法也不会报错。jQuery会根据合理的逻辑来采取不同的操作策略。例如：对于属性、CSS而言，设置操作将不会执行，获取操作将视具体情况返回undefined、null、空字符串等值。对于文档内容处理而言，jQuery会视具体情况采取不处理、或将其当作空的内容来处理等措施。

| 方法                                                         | 版本  | 描述                                                         |
| :----------------------------------------------------------- | :---- | :----------------------------------------------------------- |
| ==属性API——操作文档节点、DOM对象的属性。==                   |       |                                                              |
| [attr()](https://codeplayer.vip/p/j7snk)                     | 1.0   | 设置或返回文档节点的属性。                                   |
| [removeAttr()](https://codeplayer.vip/p/j7snl)               | 1.0   | 移除文档节点的属性。                                         |
| [prop()](https://codeplayer.vip/p/j7snm)                     | 1.6   | 设置或返回DOM元素的属性。                                    |
| [removeProp()](https://codeplayer.vip/p/j7snn)               | 1.6   | 移除每个匹配元素的属性。                                     |
| [addClass()](https://codeplayer.vip/p/j7snp)                 | 1.0   | 添加CSS类名。                                                |
| [removeClass()](https://codeplayer.vip/p/j7snq)              | 1.0   | 移除CSS类名。                                                |
| [toggleClass()](https://codeplayer.vip/p/j7snr)              | 1.2   | 切换CSS类名(存在就删除，不存在就添加)。                      |
| [html()](https://codeplayer.vip/p/j7snu)                     | 1.0   | 设置或返回元素的html内容(即innerHTML)。                      |
| [text()](https://codeplayer.vip/p/j7snv)                     | 1.0   | 设置或返回元素的文本内容(已过滤掉HTML标签，即IE中的innerText )。 |
| [val()](https://codeplayer.vip/p/j7snt)                      | 1.0   | 设置或返回元素的值(主要是表单元素的value值)。                |

## 1、jQuery.attr() 函数

`attr()`函数用于**==设置或返回当前jQuery对象所匹配的元素节点的属性值==**。

该函数属于`jQuery`对象(实例)。如果需要删除DOM元素节点的属性，请使用[removeAttr()](https://codeplayer.vip/p/j7snl)函数。

语法

`attr()`函数有以下两种用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.attr( attributeName [, value ] )
```

==设置或返回指定属性`attributeName`的值。如果指定了`value`参数，则表示设置属性`attributeName`的值为`value`；如果没有指定`value`参数，则表示返回属性`attributeName`的值==。

参数`value`还可以是函数，`attr()`将根据匹配的所有元素遍历执行该函数，函数中的`this`指针将指向对应的DOM元素。`attr()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素`attributeName`属性当前的值。函数的**返回值**就是为该元素的`attributeName`属性设置的值。

**用法二**：

*JavaScript:*

```js
jQueryObject.attr( object )
```

以对象形式同时设置任意多个属性的值。对象`object`的每个属性对应`attributeName`，属性的值对应`value`。*
*

*注意*：`attr()`函数的所有"设置属性"操作针对的是当前jQuery对象所匹配的**每一个**元素；所有"读取属性"的操作只针对**第一个**匹配的元素。

参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数          | 描述                                                         |
| :------------ | :----------------------------------------------------------- |
| attributeName | String类型指定的属性名称。                                   |
| value         | 可选/String/Function类型指定的属性值，或返回属性值的函数。   |
| object        | Object类型指定的对象，用于封装多个键值对，同时设置多项属性。 |

如果参数`value`既不是函数类型，也不是字符串类型，则会调用[toString()](https://codeplayer.vip/p/j7sgm)方法，将其转为字符串。

**返回值**

`attr()`函数的**返回值**是任意类型，**返回值**的类型取决于当前`attr()`函数执行的是"设置属性"操作还是"读取属性"操作。

如果`attr()`函数执行的是"设置属性"操作，则返回当前jQuery对象本身；如果是"读取属性"操作，则返回读取到的属性值。



如果当前jQuery对象匹配多个元素，返回属性值时，`attr()`函数只以其中第一个匹配的元素为准。如果该元素没有指定的属性，则返回`undefined`。

**prop()和attr()的主要区别**：[prop()](https://codeplayer.vip/p/j7snm)函数针对的是DOM元素(JS Element对象)的属性，`attr()`函数针对的是DOM元素所对应的文档节点的属性。详情请查看[jQuery函数attr()和prop()的区别](https://codeplayer.vip/p/j7sno)。

注意事项

1、`attr()`函数在操作少数属性时可能会出现异常情况，例如value和tabindex属性。

2、如果通过`attr()`函数更改<input>和<button>元素的`type`属性，在多数浏览器上将会抛出一个错误，因此该属性一般不允许在后期被更改。

3、尽量不要使用`attr()`操作表单元素的checked、selected、disabled属性。

在jQuery 1.6之前，`attr()`函数在检索某些属性(例如checked、selected、disabled等)时会考虑属性的值。以<input>元素的checked属性为例，如果该元素被选中，则返回`true`，否则(也就是没有checked属性)返回`false`。

从jQuery 1.6开始，对于没有的属性，`attr()`函数一律返回`undefined`。同样以<input>元素为例，如果该元素被选中，则`attr("checked")`返回checked(字符串)；否则(即没有checked属性)返回`undefined`。甚至在某些版本(例如1.6和1.11.1)中，`attr("checked")`只返回该元素初始化时的"checked"状态值，之后即使更改了选中状态，`attr("checked")`的**返回值**也不会改变。

## 2、jQuery.removeAttr() 函数

`removeAttr()`函数用于**==移除在当前jQuery对象所匹配的每一个元素节点上指定的属性==**。

该函数属于`jQuery`对象(实例)。如果你需要设置或获取元素节点上的某些属性值，你可以使用[attr()](https://codeplayer.vip/p/j7snk)函数。

语法

`removeAttr()`函数的语法如下：

*JavaScript:*

```js
jQueryObject.removeAttr( attributeNames )
```

*注意*：`removeAttr()`会移除当前jQuery对象所匹配的**每一个**元素上指定名称的属性。

参数

| 参数           | 描述                       |
| :------------- | :------------------------- |
| attributeNames | String类型指定的属性名称。 |

jQuery 1.7 新增支持：你可以传入以空格分隔的字符串，空格隔开的每个子字符串即是需要移除的属性名称。

**返回值**

`removeAttr()`函数的**返回值**是jQuery类型，返回当前jQuery对象本身。

在IE 6 ~ IE 8中，`removeAttr()`函数无法移除行内的`onclick`事件属性，为了避免潜在的问题，请使用[prop()](https://codeplayer.vip/p/j7snm)函数，相关代码如下：`jQueryObject.prop("onclick", null)`;

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
    <img id="n2" data-id="12" alt="站点名称" title="CodePlayer" src="/image/blank.gif" >
    <img id="n3" data-id="15" alt="站点logo" title="专注于编程开发技术分享" src="http://localhost/static/image/site-url.png" >
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $imgs = $("img");
// 移除所有img元素的data-id属性
$imgs.removeAttr("data-id");

var $n2 = $("#n2");
var $n3 = $("#n3");
document.writeln( $n2.attr("data-id") ); // undefined
document.writeln( $n3.attr("data-id") ); // undefined

// 从jQuery 1.7开始，可以同时移除alt和title属性
// 在jQuery 1.6之前的某些版本中，属性名称包含空格会抛出错误"Uncaught InvalidCharacterError: The string contains invalid characters. "
// 在jQuery 1.6.x中，属性名称包含空格，不会抛出错误，而是忽略掉本次移除操作
$imgs.removeAttr("alt title");
document.writeln( $n2.attr("alt") ); // undefined (站点名称){小括号内表示在jQuery 1.6.x中的输出内容，下同} 
document.writeln( $n2.attr("title") ); // undefined (CodePlayer)
document.writeln( $n3.attr("alt") ); // undefined (站点logo)
document.writeln( $n3.attr("title") ); // undefined (专注于编程开发技术分享)
```

## 3、jQuery.prop() 函数

`prop()`函数用于**==设置或返回当前jQuery对象所匹配的元素的属性值==**。

该函数属于`jQuery`对象(实例)。如果需要删除DOM元素的属性，请使用[removeProp()](https://codeplayer.vip/p/j7snn)函数。

语法

jQuery 1.6 新增该函数。`prop()`函数有以下两种用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.prop( propertyName [, value ] )
```

==设置或返回指定属性`propertyName`的值。如果指定了`value`参数，则表示设置属性`propertyName`的值为`value`；如果没有指定`value`参数，则表示返回属性`propertyName`的值==。

参数`value`还可以是函数，`prop()`将根据匹配的所有元素遍历执行该函数，函数中的`this`指针将指向对应的DOM元素。`prop()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素`propertyName`属性当前的值。函数的**返回值**就是为该元素的`propertyName`属性设置的值。

**用法二**：

*JavaScript:*

```js
jQueryObject.prop( object )
```

以对象形式同时设置任意多个属性的值。对象`object`的每个属性对应`propertyName`，属性的值对应`value`。

*注意*：`prop()`函数的所有"设置属性"操作针对的是当前jQuery对象所匹配的**每一个**元素；所有"读取属性"的操作只针对**第一个**匹配的元素。

参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数         | 描述                                                         |
| :----------- | :----------------------------------------------------------- |
| propertyName | String类型指定的属性名称。                                   |
| value        | 可选/Object/Function类型指定的属性值，或返回属性值的函数。   |
| object       | Object类型指定的对象，用于封装多个键值对，同时设置多项属性。 |

参数`value`可以是包括对象和数组在内的任意类型。

**返回值**

`prop()`函数的**返回值**是任意类型，**返回值**的类型取决于当前`prop()`函数执行的是"设置属性"操作还是"读取属性"操作。

如果`prop()`函数执行的是"设置属性"操作，则返回当前jQuery对象本身；如果是"读取属性"操作，则返回读取到的属性值。

如果当前jQuery对象匹配多个元素，返回属性值时，`prop()`函数只以其中第一个匹配的元素为准。如果该元素没有指定的属性，则返回`undefined`。

**prop()和attr()的主要区别**：`prop()`函数针对的是DOM元素(JS Element对象)的属性，[attr()](https://codeplayer.vip/p/j7snk)函数针对的是DOM元素所对应的文档节点的属性。详情请查看[jQuery函数attr()和prop()的区别](https://codeplayer.vip/p/j7sno)。

注意事项

1、如果通过`prop()`函数更改<input>和<button>元素的`type`属性，在多数浏览器上将会抛出一个错误，因为该属性一般不允许在后期更改。

2、如果使用`prop()`函数操作表单元素的checked、selected、disabled等属性，如果该元素被选中(或禁用)，则返回`true`，否则(意即HTML中没有该属性)返回`false`。

3、`prop()`函数还可以设置或返回DOM元素的`Element`对象上的某些属性，例如：tagName、selectedIndex、nodeName、nodeType、ownerDocument、defaultChecked和defaultSelected等属性。

4、在IE9及更早版本中，如果使用`prop()`函数设置的属性值不是一个简单的原始值(String、Number、Boolean)，并且在对应的DOM元素被销毁之前，该属性没有被移除，则可能会导致内存泄漏问题。如果你只是为了存储数据，建议你使用[data()](https://codeplayer.vip/p/j7snh)函数，以避免内存泄漏问题。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
   	<p id="n2" class="demo test" data-key="UUID" data_value="1235456465">CodePlayer</p>
    <input id="n3" name="order_id" type="checkbox" value="1">
    <input id="n4" name="order_id" type="checkbox" checked="checked" value="2">
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $n2 = $("#n2");
// prop()操作针对的是元素(Element对象)的属性，而不是元素节点(HTML文档)的属性
document.writeln( $n2.prop("data-key") ); // undefined
document.writeln( $n2.prop("data_value") ); // undefined

document.writeln( $n2.prop("id") ); // n2
document.writeln( $n2.prop("tagName") ); // P
document.writeln( $n2.prop("className") ); // demo test
document.writeln( $n2.prop("innerHTML") ); // CodePlayer
document.writeln( typeof $n2.prop("getAttribute") ); // function

// prop()设置的属性也是针对元素(Element对象)，因此也可以通过元素本身直接访问
$n2.prop("prop_a", "CodePlayer");
document.writeln( $n2[0].prop_a ); // CodePlayer
var n2 = document.getElementById("n2");
document.writeln( n2.prop_a ); // CodePlayer

// 以对象形式同时设置多个属性，属性值可以是对象、数组等任意类型
$n2.prop( { 
	prop_b: "baike",
	prop_c: 18,
	site: { name: "CodePlayer", url: "https://codeplayer.vip/" }
} );
document.writeln( $n2[0].prop_c ); // 18
document.writeln( $n2[0].site.url ); // https://codeplayer.vip/

// 反选所有的复选框(没选中的改为选中，选中的改为取消选中)
$("input:checkbox").prop("checked", function(index, oldValue){
	return !oldValue;
});
```

## 4、jQuery函数attr()和prop()的区别

在jQuery中，[attr()](https://codeplayer.vip/p/j7snk)函数和[prop()](https://codeplayer.vip/p/j7snm)函数都用于设置或获取指定的属性，它们的参数和用法也几乎完全相同。

但不得不说的是，这两个函数的用处却并不相同。下面我们来详细介绍这两个函数之间的区别。

#4.1、操作对象不同

很明显，attr和prop分别是单词attribute和property的缩写，并且它们均表示"属性"的意思。

不过，在jQuery中，attribute和property却是两个不同的概念。==attribute表示HTML文档节点的属性，property表示JS对象的属性==。

*JavaScript:*

```js
<!-- 这里的id、class、data_id均是该元素文档节点的attribute -->
<div id="message" class="test" data_id="123"></div>

<script type="text/javascript">
// 这里的name、age、url均是obj的property
var obj = { name: "CodePlayer", age: 18, url: "https://codeplayer.vip/" };
</script>
```

在jQuery中，`prop()`函数的设计目标是用于设置或获取指定DOM元素(指的是JS对象，Element类型)上的属性(property)；`attr()`函数的设计目标是用于设置或获取指定DOM元素所对应的文档节点上的属性(attribute)。

*JavaScript:*

```js
<!-- attr()函数针对的是该文档节点的attribute -->
<div id="message" class="test" data_id="123"></div>

<script type="text/javascript">
// prop()函数针对的是该DOM元素(msg)自身的property
var msg = document.getElementById("message");
var $msg = $(msg);
</script>
```

当然，在jQuery的底层实现中，函数`attr()`和`prop()`的功能都是通过JS原生的Element对象(如上述代码中的`msg`)实现的。`attr()`函数主要依赖的是Element对象的`getAttribute()`和`setAttribute()`两个方法。`prop()`函数主要依赖的则是JS中原生的对象属性获取和设置方式。

*JavaScript:*

```js
<div id="message" class="test" data_id="123"></div>
<script type="text/javascript">
var msg = document.getElementById("message");
var $msg = $(msg);

/* *** attr()依赖的是Element对象的element.getAttribute( attribute ) 和 element.setAttribute( attribute, value ) *** */

// 相当于 msg.setAttribute("data_id", 145);
$msg.attr("data_id", 145);

// 相当于 msg.getAttribute("data_id");
var dataId = $msg.attr("data_id"); // 145



/* *** prop()依赖的是JS原生的 element[property] 和 element[property] = value; *** */

// 相当于 msg["pid"] = "pid值";
$msg.prop("pid", "pid值");

// 相当于 msg["pid"];
var testProp = $msg.prop("pid"); // pid值
</script>
```

当然，jQuery对这些操作方式进行了封装，使我们操作起来更加方便(比如以对象形式同时设置多个属性)，并且实现了跨浏览器兼容。

此外，虽然`prop()`针对的是DOM元素的property，而不是元素节点的attribute。不过DOM元素某些属性的更改也会影响到元素节点上对应的属性。例如，property的`id`对应attribute的id，property的`className`对应attribute的class。

*JavaScript:*

```js
<div id="message" class="test" data_id="123"></div>
<script type="text/javascript">
var msg = document.getElementById("message");
var $msg = $(msg);

document.writeln( $msg.attr("class") ); // test
$msg.prop("className", "newTest");
// 修改className(property)导致class(attitude)也随之更改
document.writeln( $msg.attr("class") ); // newTest
</script>
```

#4.2、应用版本不同

`attr()`是jQuery 1.0版本就有的函数，`prop()`是jQuery 1.6版本新增的函数。毫无疑问，在1.6之前，你只能使用`attr()`函数；1.6及以后版本，你可以根据实际需要选择对应的函数。

#4.3、用于设置的属性值类型不同

==由于`attr()`函数操作的是文档节点的属性，因此设置的属性值只能是字符串类型，如果不是字符串类型，也会调用其[toString()](https://codeplayer.vip/p/j7sgm)方法，将其转为字符串类型。==

==`prop()`函数操作的是JS对象的属性，因此设置的属性值可以为包括数组和对象在内的任意类型。==

#4.4、其他细节问题

在jQuery 1.6之前，只有`attr()`函数可用，该函数不仅承担了attribute的设置和获取工作，还同时承担了property的设置和获取工作。例如：在jQuery 1.6之前，`attr()`也可以设置或获取tagName、className、nodeName、nodeType等DOM元素的property。

直到jQuery 1.6新增`prop()`函数，并用来承担property的设置或获取工作之后，`attr()`才只用来负责attribute的设置和获取工作。

此外，对于表单元素的checked、selected、disabled等属性，在jQuery 1.6之前，`attr()`获取这些属性的**返回值**为Boolean类型：如果被选中(或禁用)就返回`true`，否则返回`false`。

但是从1.6开始，使用`attr()`获取这些属性的**返回值**为String类型，如果被选中(或禁用)就返回checked、selected或disabled，否则(即元素节点没有该属性)返回`undefined`。并且，在某些版本中，这些属性值表示文档加载时的初始状态值，即使之后更改了这些元素的选中(或禁用)状态，对应的属性值也不会发生改变。

#4.5、重点：

因为jQuery认为：==attribute的checked、selected、disabled就是表示该属性初始状态的值，property的`checked`、`selected`、`disabled`才表示该属性实时状态的值(值为`true`或`false`)。==

因此，==在jQuery 1.6及以后版本中，请使用`prop()`函数来设置或获取`checked`、`selected`、`disabled`等属性。对于其它能够用`prop()`实现的操作，也尽量使用`prop()`函数。==

*JavaScript:*

```js
<input id="uid" type="checkbox" checked="checked" value="1">

<script type="text/javascript">
// 当前jQuery版本为1.11.1
var uid = document.getElementById("uid");
var $uid = $(uid);

document.writeln( $uid.attr("checked") ); // checked
document.writeln( $uid.prop("checked") ); // true

// 取消复选框uid的选中(将其设为false即可)
// 相当于 uid.checked = false;
$uid.prop("checked", false);

// attr()获取的是初始状态的值，即使取消了选中，也不会改变
document.writeln( $uid.attr("checked") ); // checked
// prop()获取的值已经发生变化
document.writeln( $uid.prop("checked") ); // false
</script>
```

## 5、jQuery.addClass() 函数

`addClass()`函数用于**==为当前jQuery对象所匹配的每一个元素添加指定的css类名==**。

该函数属于`jQuery`对象(实例)。如果你需要删除元素上的css类名，你可以使用[removeClass()](https://codeplayer.vip/p/j7snq)函数。

语法

*JavaScript:*

```js
jQueryObject.addClass( classNames )
```

*注意*：`addClass()`会为当前jQuery对象所匹配的**每一个**元素添加指定的css类名。

参数

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| classNames | String/Function类型指定的css类名，字符串可以通过空格分隔的方式来添加多个css类名。或者为返回css类名的函数 |

jQuery 1.4 新增支持：参数`classNames`可以为函数。`addClass()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`addClass()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素节点当前的class属性值。

函数的**返回值**就是为该元素添加的css类名(也可以通过空格分隔表示多个css类名)。如果**返回值**为空白字符串或者`undefined`，`addClass()`将不会为当前元素添加任何css类名。

**返回值**

`addClass()`函数的**返回值**是jQuery类型，返回当前jQuery对象本身。

==`addClass()`函数只是在原有css类名的基础上，添加新的css类名，并不会覆盖掉之前已存在的css类名。如果待添加的css类名已经存在，`addClass()`并不会重复添加。==

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
   	<p id="n2" class="demo test">CodePlayer</p>
   	<p id="n3" class="foo">专注于编程开发技术分享</p>
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $n2 = $("#n2");
// 为n2添加一个css类名
$n2.addClass("newOne");
document.writeln( $n2.attr("class") ); // demo test newOne

var $n3 = $("#n3");
// 为n3添加3个css类名
$n3.addClass("test class1 class2");
document.writeln( $n3.attr("class") ); // foo test class1 class2

// 为所有p标签添加css类名"item-index"，这里的index表示当前元素在所有匹配元素中的索引
$("p").addClass( function(index, classNames){
	// 函数内的this表示当前DOM元素
	return "item-" + index;
} );

document.writeln( $("#n2").attr("class") ); // demo test newOne item-0
document.writeln( $("#n3").attr("class") ); // foo test class1 class2 item-1
```

## 6、jQuery.toggleClass() 函数

`toggleClass()`函数用于**==切换当前jQuery对象所匹配的每一个元素上指定的css类名==**。

==所谓"切换"，就是如果该元素上已存在指定的类名，则移除掉；如果不存在，则添加该类名==。

该函数属于`jQuery`对象(实例)。

语法

`toggleClass()`函数的用法比较复杂，其主要有以下两种用法：

**用法一**：

*JavaScript:*

```js
// 参数类型( string )是 v 1.0的用法
// 参数类型( string, boolean )是 v 1.3新增用法
// 参数类型( function [, boolean] )是 v 1.4 新增用法
jQueryObject.toggleClass( classNames [, switch ] )
```

切换指定的css类名`classNames`。如果存在指定的类名，则移除该类名；如果存在，则添加该类名。

参数`switch`用于指定是只添加还是只移除指定的css类名。

**用法二**：jQuery 1.4 新增该用法。

*JavaScript:*

```js
jQueryObject.toggleClass( [ switch ] )
```

只要该元素有css类名，或者`switch`参数为`false`，`toggleClass()`将移除该元素所有的css类名。否则(其他任何情况)，都会将元素的class属性重置为最近一次调用`toggleClass()`函数(必须是该用法)时的有效class属性值("有效"意即不为空)。如果没有有效的class属性值，则重置class属性为空字符串。

*注意*：`toggleClass()`会"切换"当前jQuery对象所匹配的**每一个**元素上指定的css类名。

参数

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| classNames | String/Function类型指定的css类名，字符串可以通过空格分隔的方式来添加多个css类名。或者为返回css类名的函数。 |
| switch     | Boolean类型一个布尔值，用于指定是添加还是移除css类名。`true`表示添加，`false`表示移除。 |

jQuery 1.4 新增支持：参数`className`可以为函数。`toggleClass()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`toggleClass()`还会为函数传入3个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素节点当前的class属性值，第三个参数就是调用`toggleClass()`时传入的`switch`参数。

函数的**返回值**就是该元素需要切换的css类名(也可以通过空格分隔表示多个css类名)。如果**返回值**为空白字符串或者`undefined`，`toggleClass()`将不会为当前元素切换任何css类名。

**返回值**

`toggleClass()`函数的**返回值**是jQuery类型，返回当前jQuery对象本身。

示例&说明

以下是`toggleClass()`函数应用时的部分等价代码，你可以参考理解。

*JavaScript:*

```js
$element.toggleClass( className );
// 相当于
if( $element.hasClass( className ) ){
	$element.removeClass( className );
}else{
	$element.addClass( className );	
}
//上面的className均表示单个css类名，如果是空格分隔的多个css类名，则等价部分的代码是需要循环执行的

/* ********** 分割线 ********** */

$element.toggleClass( className, true );
//相当于
$element.addClass( className );	

/* ********** 分割线 ********** */

$element.toggleClass( className, false );
//相当于
$element.removeClass( className );
```

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
   	<p id="n2" class="demo test">CodePlayer</p>
   	<p id="n3" class="foo">专注于编程开发技术分享</p>
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
// 以下注释中的"当前"均表示在该函数执行之前

var $n2 = $("#n2");
// 切换n2上的一个css类名(当前有"demo"，切换后无"demo")
$n2.toggleClass("demo");
document.writeln( $n2.attr("class") ); // test

//切换n2上的2个css类名(当前无"demo"有"test"，切换后则有"demo"无"test")
$n2.toggleClass("demo test");
document.writeln( $n2.attr("class") ); // demo

var $n3 = $("#n3");
// 为n3添加2个css类名(类名"foo"已存在，不会重复添加)
// 相当于 $n3.addClass("foo bar");
$n3.toggleClass("foo bar", true);
document.writeln( $n3.attr("class") ); // foo bar

// 移除所有的css类名(当前的class属性值为"foo bar"，有css类名，内部会先存档再移除)
$n3.toggleClass(false);
document.writeln( $n3.attr("class") ); // (空字符串)

// 恢复为上一次保存的class属性值(当前的class属性值为""，没有css类名，内部不会保存)
// 此时switch不为false，并且元素没有css类名，因此会恢复为之前保存的class属性值("foo bar")
$n3.toggleClass(true);
document.writeln( $n3.attr("class") ); // foo bar

// 移除n3上的一个css类名
// 相当于 $n3.removeClass("bar");
$n3.toggleClass("bar", false);
document.writeln( $n3.attr("class") ); // foo

// 移除所有的css类名(当前的class属性值为"foo"，有css类名，内部会先存档再移除)
// 由于当前有css类名，因此无论参数是true还是false，都会移除全部的css类名 
$n3.toggleClass(true);
document.writeln( $n3.attr("class") ); // (空字符串)

// 恢复为上次保存的class属性值(当前的class属性值为""，没有css类名，内部不会保存)
//此时switch不为false，并且元素没有css类名，因此会恢复为之前保存的class属性值("foo")
$n3.toggleClass(true);
document.writeln( $n3.attr("class") ); // foo

// 当前有css类名，移除所有的css类名(当前的class属性值为"foo"，有css类名，内部会先存档再移除)
// 相当于 $n3.toggleClass(true);
$n3.toggleClass();
document.writeln( $n3.attr("class") ); // (空字符串)

// 当前无css类名，恢复为上次保存的class属性值(当前的class属性值为""，没有css类名，内部不会保存)
//此时switch不为false，并且元素没有css类名，因此会恢复为之前保存的class属性值("foo")
$n3.toggleClass();
document.writeln( $n3.attr("class") ); // foo

// 切换、强制添加操作针对print-index和printed两个类名
// 移除只针对print-index (index表示当前元素在匹配元素中的索引)
function callback(index, classNames, _switch){
	// 函数内部的this指向迭代的当前DOM元素
	if( _switch === false){
		return "print-" + index;
	}else{ // true 或 undefined
		return "print-" + index + " printed";
	}	
}

// 这里的true，就是传递给函数callback的第三个参数_switch的值
$("p").toggleClass( callback, true);
```

## 7、jQuery.html() 函数

`html()`函数用于**==设置或返回当前jQuery对象所匹配的DOM元素内的html内容==**。

==该函数的用途相当于设置或获取DOM元素的`innerHTML`属性值==。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.html( [ htmlString ] )
```

参数

| 参数       | 描述                                           |
| :--------- | :--------------------------------------------- |
| htmlString | 可选/String/Function类型用于设置的html字符串。 |

如果没有指定`htmlString`参数，则表示获取**第一个匹配元素**的html内容；如果指定了`htmlString`参数，则表示设置**所有匹配元素**的html内容。

jQuery 1.4 新增支持：参数`htmlString`可以为函数。`html()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`html()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素当前的html内容。函数的**返回值**就是需要为该元素设置的html内容。

如果参数`htmlString`不是字符串或函数类型，则会被转换为字符串类型( [toString()](https://codeplayer.vip/p/j7sgm) )。如果参数为`null`或`undefined`，则将其视作空字符串("")。

**返回值**

`html()`函数的**返回值**是String/jQuery类型，**返回值**的实际类型取决于`html()`函数所执行的操作。

如果`html()`函数执行的是设置操作，将返回当前jQuery对象本身。如果执行的是获取操作，将返回第一个匹配元素的html内容，该值为字符串类型。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1">
	<p id="n2">Hello</p>
	<p id="n3">
		CodePlayer
		<span id="n4">专注于编程开发技术分享</span>
		<span id="n5"></span>
	</p>
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $n2 = $("#n2");
alert( $n2.html() ); // Hello
// 设置n2的html内容
$n2.html( '<strong>Hello World</strong>' );

var $n3 = $("#n3");
alert( $n3.html() );
/*
CodePlayer
<span id="n4">专注于编程开发技术分享</span>
<span id="n5"></span>
*/

// 清空所有span元素的html内容(将html内容设为"")
$("span").html( "" );

// 将所有p元素的html内容改为"第<em>N</em>个p元素，id为this.id"
// 这里的N表示该元素在所有匹配元素中的序号(1、2、3……)
// this.id是该元素的id属性值
$("p").html( function(index, currentHtml){
	// 函数内的this指向当前迭代的p元素
	return "第<em>" + (index + 1) + "</em>个p元素，id为" + this.id;	
});
```

## 8、jQuery.text() 函数

`text()`函数用于**==设置或返回当前jQuery对象所匹配的DOM元素内的text内容==**。

所谓text内容，就是在该元素的html内容(即`innerHTML`属性值)的基础上过滤掉所有HTML标记后的文本内容(即IE浏览器的DOM元素特有的`innerText`属性值)。

如果jQuery对象匹配的元素不止一个，则`text()`返回合并了每个匹配元素(包含其后代元素)中的文本内容后的字符串。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.text( [ textString ] )
```

参数

| 参数       | 描述                                           |
| :--------- | :--------------------------------------------- |
| textString | 可选/String/Function类型用于设置的text字符串。 |

如果没有指定`textString`参数，则表示获取合并了**每一个匹配元素**中的内容后的text内容；如果指定了`textString`参数，则表示设置**所有匹配元素**的text内容。

jQuery 1.4 新增支持：参数`textString`可以为函数。`text()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。



`text()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素当前的text内容。函数的**返回值**就是需要为该元素设置的text内容。

如果参数`textString`不是字符串或函数类型，则会被转换为字符串类型( [toString()](https://codeplayer.vip/p/j7sgm) )。如果参数为`null`或`undefined`，则将其视作空字符串("")。

**返回值**

`text()`函数的**返回值**是String/jQuery类型，**返回值**的实际类型取决于`text()`函数所执行的操作。

如果`text()`函数执行的是设置操作，将返回当前jQuery对象本身。如果执行的是获取操作，将返回合并了每一个匹配元素中的内容后的text内容，该值为字符串类型。

示例&说明

以下面这段text代码为例：

*Text:*

```html
<div id="n1">
	<p id="n2">Hello</p>
	<p id="n3">
		CodePlayer
		<span id="n4">专注于编程开发技术分享</span>
		<span id="n5"></span>
	</p>
	<ul>
		<li>item1</li>
		<li>item1</li>
		<li>item1</li>
	</ul>
</div>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $n2 = $("#n2");
alert( $n2.text() ); // Hello
// 设置n2的text内容
$n2.text( "Hello World" );

alert($("p").text()); // 返回"Hello World\nCodePlayer\n专注于编程开发技术分享\n"
// 由于不同浏览器的HTML解析器差异，返回的文本在换行符或其他空白字符方面也可能不同。

var $n3 = $("#n3");
// 返回的是过滤掉HTML标记的文本内容
alert( $n3.text() );
/*
CodePlayer
专注于编程开发技术分享
*/

var $n5 = $("#n5");
// 虽然设置的内容中包含符合html标签的字符串，但是这些都会被当作文本内容看待，而不会被当作html内容来看待
// 因此页面上将显示字符串"<strong>Hello World</strong>"，而不是粗体的"Hello World"。
// 这相当于$5.html( '&lt;strong&gt;Hello World&lt;/strong&gt;' );
$n5.text( '<strong>Hello World</strong>' );
alert( $n5.text() ); // <strong>Hello World</strong>


// 清空所有span元素的text内容(将text内容设为"")
$("span").text( "" );

// 将所有li元素的text内容改为"第N个<li>元素"
// 这里的N表示该元素在所有匹配元素中的序号(1、2、3……)
$("li").text( function(index, currentText){
	// 函数内的this指向当前迭代的li元素
	return "第" + (index + 1) + "个<li>元素";	
});
```

## 9、jQuery.val() 函数

`val()`函数用于**==设置或返回当前jQuery对象所匹配的DOM元素的value值==**。

==该函数常用于设置或获取表单元素的value属性值。例如：`<input>、<textarea>、<select>、<option>、<button>`等。==

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.val( [ values ] )
```

参数

| 参数   | 描述                                              |
| :----- | :------------------------------------------------ |
| values | 可选/String/Array/Function类型用于设置的value值。 |

如果没有指定`values`参数，则表示获取**第一个匹配元素**的value值；如果指定了`value`参数，则表示设置**所有匹配元素**的value值。

jQuery 1.4 新增支持：参数`values`可以为函数。`val()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`val()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素当前的value属性值。函数的**返回值**就是需要为该元素设置的value值。

如果参数`values`为`null`或`undefined`，则将其视作空字符串("")。如果参数`values`不是字符串或函数类型，并且当前元素不是多选的选择框(多选选择框会特殊处理数组类型)，则其他类型的值均会被转换为字符串( [toString()](https://codeplayer.vip/p/j7sgm) )。

**返回值**

`val()`函数的**返回值**是String/Array/jQuery类型，**返回值**的实际类型取决于`val()`函数所执行的操作。

如果`val()`函数执行的是设置操作，将返回当前jQuery对象本身。如果执行的是获取操作，将返回第一个匹配元素的value属性值，该值一般为字符串类型；如果该元素是多选的<select>元素，则返回包含所有选中值的数组。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<form id="n1" name="myForm" method="post">
	<input id="n2" class="normal" name="username" type="text" ><br>
	<input id="n3" class="normal" name="password" type="password" value="123456" ><br>
	<input id="n4" class="normal" name="user_id" type="hidden" value="1" ><br>
	
	<input id="n5" name="uid" type="checkbox" value="12" >12
	<input id="n6" name="uid" type="checkbox" checked="checked" value="13" >13
	<input id="n7" name="uid" type="checkbox" checked="checked" value="14" >14<br>
	
	<input id="n8" name="gender" type="radio" checked="checked" value="men" >男
	<input id="n9" name="gender" type="radio" value="women" >女<br>
	
	<textarea id="n10" name="content" rows="3" cols="80">此处是内容</textarea><br>
	
	<select id="n11" name="answer">
		<option value="A">选项A</option>
		<option value="B" selected="selected">选项B</option>
		<option value="C">选项C</option>
		<option value="D">选项D</option>
	</select><br>
	
	<select id="n12" name="multiAnswer" multiple="multiple">
		<option value="A">A</option>
		<option value="B">B</option>
		<option value="C" selected="selected">C</option>
		<option value="D" selected="selected">D</option>
	</select><br>
</form>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $n2 = $("#n2");
document.writeln( $n2.val() ); // (空字符串)
// 设置n2的value为"CodePlayer"
$n2.val("CodePlayer");

var $n3 = $("#n3");
document.writeln( $n3.val() ); // 123456
// 设置n3的value为""
$n3.val("");

 // 将含有类名normal的所有input元素的value设为"123"
$("input.normal").val( "123" );
document.writeln( $n2.val() ); // 123
document.writeln( $n3.val() ); // 123
document.writeln( $("#n4").val() ); // 123

var $checkedUid = $("[name=uid]:checked");
// 虽然匹配的元素有n6、n7两个，但只会获取第一个匹配元素的值
document.writeln( $checkedUid.val() ); // 13

var $checkedGender = $("[name=gender]:checked");
document.writeln( $checkedGender.val() ); // men

// 如果单选按钮的value为"men"和"women"，将其改为"男"和"女"
$(":radio").val( function(index, currentValue){
	// 函数内的this指向当前迭代的DOM元素
	if( currentValue == "men"){
		return "男";
	}else if( currentValue == "women"){
		return "女";
	}else { // 其他值不变
		return currentValue;
	}
});

var $n9 = $("#n10");
document.writeln( $n9.val() ); // 此处是内容
$n9.val("新的内容");

var $n10 = $("#n11");
document.writeln( $n10.val() ); // B
// 将单选的选择框的选中项改为value为C的option
$n10.val("C");

var $n11 = $("#n12");
document.writeln( $n11.val() ); // C,D
// 将多选的选择框的选中项改为value分别为A、B、C的3个option
$n11.val( ["A", "B", "C"] );
```

# 五、文档操作

## 0、jQuery对象的文档操作方法

> *版本说明*：如果"版本"列的版本号带有删除线(例如： ~~1.8~~)，表示从该版本开始，此方法 **已过时**。如果版本号带有删除线，并且为红色(例如： ~~1.9~~)，表示从该版本开始，此方法已 **被移除**。

*注意*：
如果当前jQuery对象匹配多个DOM元素，那么我们执行该对象的下列方法时：如果当前执行的是"写"操作，则作用于每一个匹配的元素；如果当前执行的是"读"操作，则只作用于第一个匹配的元素。
以使用`attr()`方法为例：如果我们用它来设置属性，它将会为匹配的每一个元素都设置属性；如果用它来读取属性，则它只会获取第一个匹配元素对应的属性值。

如果当前jQuery对象不匹配任何元素，执行以下方法也不会报错。jQuery会根据合理的逻辑来采取不同的操作策略。例如：对于属性、CSS而言，设置操作将不会执行，获取操作将视具体情况返回undefined、null、空字符串等值。对于文档内容处理而言，jQuery会视具体情况采取不处理、或将其当作空的内容来处理等措施。

| 方法                                                         | 版本  | 描述                                                         |
| :----------------------------------------------------------- | :---- | :----------------------------------------------------------- |
| ==内容操作——插入、修改、删除文档节点。==                     |       |                                                              |
| [append()](https://codeplayer.vip/p/j7sp2)                   | 1.0   | 向每个匹配元素内部的末尾位置追加内容。                       |
| [appendTo()](https://codeplayer.vip/p/j7sp3)                 | 1.0   | 将所有匹配元素追加到目标元素内部的末尾位置。                 |
| [prepend()](https://codeplayer.vip/p/j7sp4)                  | 1.0   | 向每个匹配元素内部的开头位置追加内容。                       |
| [prependTo()](https://codeplayer.vip/p/j7sp5)                | 1.0   | 将所有匹配元素追加到目标元素内部的开头位置。                 |
| [after()](https://codeplayer.vip/p/j7sp6)                    | 1.0   | 在每个匹配元素之后插入内容。                                 |
| [before()](https://codeplayer.vip/p/j7sp7)                   | 1.0   | 在每个匹配元素之前插入内容。                                 |
| [insertAfter()](https://codeplayer.vip/p/j7sp8)              | 1.0   | 将所有匹配元素插入到目标元素之后。                           |
| [insertBefore()](https://codeplayer.vip/p/j7sp9)             | 1.0   | 将所有匹配元素插入到目标元素之前。                           |
| [wrap()](https://codeplayer.vip/p/j7spa)                     | 1.0   | 在每个匹配元素外包裹指定的HTML结构。                         |
| [unwrap()](https://codeplayer.vip/p/j7spc)                   | 1.4   | 移除每个匹配元素的父元素的HTML标签。                         |
| [wrapAll()](https://codeplayer.vip/p/j7spb)                  | 1.2   | 将所有匹配元素用单个HTML结构包裹起来                         |
| [wrapInner()](https://codeplayer.vip/p/j7spe)                | 1.2   | 在每个匹配元素内侧(所有子节点外侧)包裹指定的HTML结构。       |
| [replaceWith()](https://codeplayer.vip/p/j7spf)              | 1.2   | 将每个匹配元素替换成指定的HTML内容或DOM元素。                |
| [replaceAll()](https://codeplayer.vip/p/j7spg)               | 1.2   | 使用所有匹配的元素替换掉每个目标元素。                       |
| [empty()](https://codeplayer.vip/p/j7spd)                    | 1.0   | 清空每个匹配元素的html内容。                                 |
| [remove()](https://codeplayer.vip/p/j7sph)                   | 1.0   | 移除所有的匹配元素，包括它的附加数据和绑定事件。             |
| [detach()](https://codeplayer.vip/p/j7spi)                   | 1.0   | 移除所有的匹配元素，但在jQuery对象上保留其附加数据和绑定事件。 |
| [clone()](https://codeplayer.vip/p/j7spj)                    | 1.0   | 克隆所有的匹配元素。                                         |

## 1、jQuery.append() 函数

`append()`函数用于**==向每个匹配元素内部的末尾位置追加指定的内容==**。

指定的内容可以是：html字符串、DOM元素(或数组)、jQuery对象、函数(**返回值**)。

与该函数**相对**的是[prepend()](https://codeplayer.vip/p/j7sp4)函数，用于向每个匹配元素内部的起始位置追加指定的内容。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.append( content1 [, content2 [, contentN ]] )
```

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| content1 | String/Element/jQuery/Function类型指定的追加内容。           |
| content2 | 可选/String/Element/jQuery类型指定的追加内容。               |
| contentN | 可选/String/Element/jQuery类型指定的追加内容，可以有任意多个。 |

`append()`可以将多个参数所表示的内容依次追加到每个匹配元素内部的末尾位置。如果参数为字符串类型，则将其视作html字符串。

jQuery 1.4 新增支持：参数`content1`可以为函数。`append()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。



`append()`还会为函数传入两个参数：第一个参数就是当前元素在匹配元素中的索引，第二个参数就是该元素当前的内部html内容(innerHTML)。函数的**返回值**就是需要为该元素追加的内容(可以是html字符串、DOM元素、jQuery对象)。

*注意*：只有**第一个参数**可以为自定义函数，用于遍历执行。如果之后的参数也为函数，则调用其[toString()](https://codeplayer.vip/p/j7sgm)方法，将其转为字符串，并视为html内容。

**返回值**

`append()`函数的**返回值**为jQuery类型，返回当前jQuery对象本身(以便于进行链式风格的编程)。

*注意*：如果追加的内容是当前页面中的某些元素，那么这些元素将**从原位置上消失**。简而言之，这相当于一个移动操作，而不是复制操作。

示例&说明

`append()`函数用于将每个匹配元素内部的末尾位置追加内容：

*HTML:*

```html
<p>段落文本1<span></span><!--插入到p元素内部的末尾位置--></p>
<p>段落文本2<span></span><!--插入到p元素内部的末尾位置--></p>


<script type="text/javascript">
$("p").append( '<!--插入到p元素内部的末尾位置-->' ); 
</script>
```

请注意`append()`函数和[appendTo()](https://codeplayer.vip/p/j7sp3)函数的区别：

*JavaScript:*

```js
var $A = $("s1");
var $B = $("s2");


// 将$B追加到$A中
$A.append( $B ); // 返回$A
// 将$A追加到$B中
$A.appendTo( $B ); // 返回表示追加内容的jQuery对象( 匹配所有$B内部末尾追加的$A )
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<span id="n2">CodePlayer</span>    
</p>
<p id="n3">
	<label class="move">Hello World</label>
</p>
<p id="n4">
	<i>测试内容</i>
</p>
```

以下jQuery示例代码用于演示`append()`函数的具体用法：

*JavaScript:*

```js
var $n1 = $("#n1");
// 将一个strong标记追加到n1内部的末尾位置
$n1.append( '<strong>追加内容</strong>' );


// 将所有的label元素和i元素追加到n1内部的末尾位置
// 原来位置的label元素和i元素会消失(相当于是移动到n1内部的末尾位置)
$n1.append( document.getElementsByTagName("label"), $("i") );

// 为每个p元素内部的末尾位置追加一个span元素，html内容根据索引而有所不同
var $p = $("p");
$p.append( function(index, html){
	return '<span>追加元素' + (index + 1) + '</span>';	
} );
```

`append()`会将内容追加到指定容器元素的**结束标记之前**，**不会额外添加任何空白字符**，上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<p id="n1">
	<span id="n2">CodePlayer</span>    
<strong>追加内容</strong><label class="move">Hello World</label><i>测试内容</i><span>追加元素1</span></p>
<p id="n3">
	
<span>追加元素2</span></p>
<p id="n4">
	
<span>追加元素3</span></p>
```

## 2、jQuery.appendTo() 函数

`appendTo()`函数用于**==将当前所有匹配元素追加到指定元素内部的末尾位置==**。

与该函数**相对**的是[prependTo()](https://codeplayer.vip/p/j7sp5)函数，用于将当前所有匹配元素追加到指定元素内部的起始位置。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.appendTo( target )
```

参数

| 参数   | 描述                                                         |
| :----- | :----------------------------------------------------------- |
| target | String/Element/jQuery类型指定的目标元素，以便于向其中追加当前匹配的元素。 |

如果参数`target`为字符串类型，则将其视作jQuery选择器或html内容字符串，jQuery会自行判断。

**返回值**

`appendTo()`函数的**返回值**为jQuery类型，返回表示追加的内容的jQuery对象。

*注意*：如果当前jQuery对象匹配的元素是当前页面中的某些元素，那么这些元素将**从原位置上消失**。简而言之，这相当于一个移动操作，而不是复制操作。

示例&说明

`appendTo()`函数用于将所有匹配元素追加到指定元素内部的末尾位置追加内容：

*JavaScript:*

```js
<p>段落文本1<span></span></p>
<p>段落文本2<span></span></p>

<!--以上是jQuery代码执行前的html内容-->
<script type="text/javascript">
$('<!--插入到p元素内部的末尾位置-->').appendTo( "p" );
// 其**返回值**就是匹配追加内容(两个注释元素'<!--插入到p元素内部的末尾位置-->')的jQuery对象
</script>
<!--以下是jQuery代码执行后的html内容-->

<p>段落文本1<span></span><!--插入到p元素内部的末尾位置--></p>
<p>段落文本2<span></span><!--插入到p元素内部的末尾位置--></p>
```

请注意`appendTo()`函数和[append()](https://codeplayer.vip/p/j7sp2)函数的区别：

*JavaScript:*

```js
var $A = $("s1");
var $B = $("s2");


// 将$A追加到$B中
$A.appendTo( $B ); // 返回表示追加内容的jQuery对象( 匹配所有$B内部末尾追加的$A )
// 将$B追加到$A中
$A.append( $B ); // 返回$A
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<span id="n2">CodePlayer</span>    
</p>
<p id="n3">
	<label id="n4" class="move">Hello World</label>
</p>
<p id="n5">
	<span id="n6">测试内容</span>
</p>
```

以下jQuery示例代码用于演示`appendTo()`函数的具体用法：

*JavaScript:*

```js
// 将n4追加到n1内部的末尾位置
// n4将从原位置上消失
$("#n4").appendTo( "#n1" );

// 将所有的span元素追加到n3内部的末尾位置
// span元素将从原位置上消失
$("span").appendTo( "#n3" );

// 将一个自定义的i元素追加到n6和n1内部的末尾位置
$('<i>追加的内容</i>').appendTo( [document.getElementById("n6"), document.getElementById("n1")] );

// 将一个自定义的span元素追加到一个临时的span元素中，再将其追加到所有p元素内部的末尾位置
$('<strong>追加文本</strong>').appendTo("<span/>").appendTo( $("p") );
```

`appendTo()`会将当前匹配元素追加到目标容器元素的**结束标记之前**，**不会额外添加任何空白字符**，上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<p id="n1">
	   
<label id="n4" class="move">Hello World</label><i>追加的内容</i><strong>追加文本</strong></p>
<p id="n3">
	
<span id="n2">CodePlayer</span><span id="n6">测试内容<i>追加的内容</i></span><strong>追加文本</strong></p>
<p id="n5">
	
<strong>追加文本</strong></p>
```

## 3、jQuery.after() 函数

`after()`函数用于**==在每个匹配元素之后插入指定的内容==**。

指定的内容可以是：html字符串、DOM元素(或数组)、jQuery对象、函数(**返回值**)。

与该函数**相对**的是[before()](https://codeplayer.vip/p/j7sp7)函数，用于在每个匹配元素之前插入指定的内容。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.after( content1 [, content2 [, contentN ]] )
```

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| content1 | String/Element/jQuery/Function类型指定的追加内容。           |
| content2 | 可选/String/Element/jQuery类型指定的追加内容。               |
| contentN | 可选/String/Element/jQuery类型指定的追加内容，可以有任意多个。 |

`after()`可以将多个参数所表示的内容全部插入到紧邻每个匹配元素之后的位置。如果参数为字符串类型，则将其视作html字符串。

jQuery 1.4 新增支持：参数`content1`可以为函数。`after()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。



`after()`还会为函数传入两个参数：第一个参数就是当前元素在匹配元素中的索引，第二个参数就是该元素当前的内部html内容(innerHTML)。函数的**返回值**就是需要插入的内容(可以是html字符串、DOM元素、jQuery对象)。

*注意*：只有**第一个参数**可以为自定义函数，用于遍历执行。如果之后的参数也为函数，则调用其[toString()](https://codeplayer.vip/p/j7sgm)方法，将其转为字符串，并视为html内容。

**返回值**

`after()`函数的**返回值**为jQuery类型，返回当前jQuery对象本身(以便于进行链式风格的编程)。

*注意*：如果插入的内容是当前页面中的某些元素，那么这些元素将**从原位置上消失**。简而言之，这相当于一个移动操作，而不是复制操作。

示例&说明

`after()`函数用于在每个匹配元素之后的位置插入内容：

```html
<p>段落文本1<span></span></p><!--插入到p元素之后的位置-->
<p>段落文本2<span></span></p><!--插入到p元素之后的位置-->


<script type="text/javascript">
$("p").after( '<!--插入到p元素之后的位置-->' ); 
</script>
```

请注意`after()`函数和[insertAfter()](https://codeplayer.vip/p/j7sp8)函数的区别：

*JavaScript:*

```js
var $A = $("s1");
var $B = $("s2");


// 将$B插入到$A之后
$A.after( $B ); // 返回$A
// 将$A插入到$B之后
$A.insertAfter( $B ); // 返回表示插入内容的jQuery对象( 匹配所有$B之后插入的$A元素 )
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<span id="n2">span#n2</span>    
</p>
<p id="n3">
	<label id="n4">label#n4</label>
	<i id="n5">i#n5</i>
</p>
```

以下jQuery示例代码用于演示`after()`函数的具体用法：

*JavaScript:*

```js
// 在n4之后插入一个自定义的span元素
$("#n4").after('<span id="n6">span#n6(new)</span>');

// 在n2之后插入n5
// n5将从原位置上消失
$("#n2").after( document.getElementById("n5") );

// 在每个span元素之后插入自定义的strong元素
$("span").after( function(index, innerHTML){
	return '<strong>strong元素' + (index + 1) + '</strong>';
} );
```

`after()`会将内容插入指定元素的**结束标记之后**，**不会额外添加任何空白字符**，上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<p id="n1">
	<span id="n2">span#n2</span><strong>strong元素1</strong><i id="n5">i#n5</i>    
</p>
<p id="n3">
	<label id="n4">label#n4</label><span id="n6">span#n6(new)</span><strong>strong元素2</strong>
	
</p>
```

## 4、jQuery.insertAfter() 函数

`insertAfter()`函数用于**==将当前所有匹配元素插入到指定元素之后==**。

与该函数**相对**的是[insertBefore()](https://codeplayer.vip/p/j7sp9)函数，用于将当前所有匹配元素插入到指定元素之前。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.insertAfter( target )
```

参数

| 参数   | 描述                                                         |
| :----- | :----------------------------------------------------------- |
| target | String/Element/jQuery类型指定的目标元素，以便于在该目标之后插入当前匹配的元素。 |

如果参数`target`为字符串类型，则将其视作jQuery选择器或html内容字符串，jQuery会自行判断。

**返回值**

`insertAfter()`函数的**返回值**为jQuery类型，返回表示插入内容的jQuery对象。

*注意*：如果当前jQuery对象匹配的元素是当前页面中的某些元素，那么这些元素将**从原位置上消失**。简而言之，这相当于一个移动操作，而不是复制操作。

示例&说明

`insertAfter()`函数用于将所有匹配元素插入到指定元素之后的位置：

*JavaScript:*

```js
<p>段落文本1<span></span></p>
<p>段落文本2<span></span></p>

<!--以上是jQuery代码执行前的html内容-->
<script type="text/javascript">
$('<!--插入到p元素之后的位置-->').insertAfter( "p" );
// 其**返回值**就是匹配插入内容(两个注释元素'<!--插入到p元素之后的位置-->')的jQuery对象
</script>
<!--以下是jQuery代码执行后的html内容-->

<p>段落文本1<span></span></p><!--插入到p元素之后的位置-->
<p>段落文本2<span></span></p><!--插入到p元素之后的位置-->
```

请注意`insertAfter()`函数和[after()](https://codeplayer.vip/p/j7sp6)函数的区别：

*JavaScript:*

```js
var $A = $("s1");
var $B = $("s2");


// 将$A插入到$B之后
$A.insertAfter( $B ); // 返回表示插入内容的jQuery对象( 匹配所有$B之后插入的$A元素 )
// 将$B插入到$A之后
$A.after( $B ); // 返回$A
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<span id="n2">span#n2</span>    
</p>
<p id="n3">
	<label id="n4" class="move">label#n4</label>
</p>
<p id="n5">
	<span id="n6">span#n6</span>
</p>
```

以下jQuery示例代码用于演示`insertAfter()`函数的具体用法：

*JavaScript:*

```js
// 将一个自定义的i元素插入到n4之后
$('<i>i元素</i>').insertAfter( "#n4" );

// 将n4插入到n2之后
// n4将从原位置上消失
$('#4').insertAfter( document.getElementById("n2") );

//将一个自定义的strong元素插入到每个span元素之后
$("<strong>插入文本</strong>").insertAfter( "span" );
```

`insertAfter()`会将当前匹配元素插入到目标元素的**结束标记之后**，**不会额外添加任何空白字符**，上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<p id="n1">
	<span id="n2">span#n2</span><strong>插入文本</strong>    
</p>
<p id="n3">
	<label id="n4" class="move">label#n4</label><i>i元素</i>
</p>
```

## 5、jQuery.wrap() 函数

`wrap()`函数用于**==在每个匹配元素外部包裹指定的HTML结构==**。

与该函数**相对**的是[unwrap()](https://codeplayer.vip/p/j7spc)函数，用于当前匹配元素的父元素(只移除父元素，其内部节点全部保留)。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.wrap( wrapper )
```

参数

| 参数    | 描述                                                       |
| :------ | :--------------------------------------------------------- |
| wrapper | String/Element/jQuery/Function类型用于包裹匹配元素的节点。 |

如果参数`wrapper`为字符串，则将其视作jQuery选择器或html字符串，jQuery会自行判断。

jQuery 1.4 新增支持：参数`wrapper`可以为函数。`wrap()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`wrap()`还会为函数传入一个参数，即当前元素在匹配元素中的索引。函数的返回值就是用于包裹的节点内容(可以是html字符串、DOM元素或jQuery对象)。

*注意*：如果`wrapper`匹配多个元素，则只将第一个元素作为包裹元素。

*注意*：如果`wrapper`是多层嵌套的元素(例如<p><i></i></p>)，`wrap()`将从外往内检查每层嵌套的第一个节点。如果该节点没有子节点或者第一个子节点不是Element节点(比如文本节点、注释节点等)，就停止向内查找，直接在当前节点内部的末尾位置追加([append()](https://codeplayer.vip/p/j7sp2))当前匹配元素。

返回值

`wrap()`函数的返回值为jQuery类型，返回当前jQuery对象本身(以便于进行链式风格的编程)。

*注意*：即使`wrapper`元素是当前页面中的元素，该元素也不会从原位置上消失。因为`wrap()`使用的是该元素的副本(克隆)来充当包裹。

示例&说明

`wrap()`函数用于在每个匹配元素之前的位置插入内容：

*JavaScript:*

```js
<p>段落文本1<span></span></p>
<p>段落文本2<span></span></p>

<script type="text/javascript">
$("p").wrap( '<div></div>' ); 
</script>

<!--以下是jQuery代码执行后的html内容-->
<div><p>段落文本1<span></span></p></div>
<div><p>段落文本2<span></span></p></div>
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<span id="n2">span#n2</span>    
</p>
<p id="n3">
	<input id="n4" type="text" />
</p>
<span id="n5">多层嵌套1</span>
<span id="n6">多层嵌套2</span>
```

以下jQuery示例代码用于演示`wrap()`函数的具体用法：

*JavaScript:*

```js
// 在n2元素外包裹strong元素：<strong>{#n2}</strong>
$("#n2").wrap('<strong/>');


// 在n4元素外包裹form元素：<form name="myForm">{#n4}</form>
$("#n4").wrap('<form name="myForm"></form>');


// 在每个p元素外包裹div元素：<div data_id="index">{p}</div>
$("p").wrap( function(index){
	return '<div data_id="' + index + '"></div>';	
} );


// 在n5元素外包裹嵌套的div元素：<div><p><em><b>{#n5}</b></em></p></div>
$("#n5").wrap( '<div><p><em><b></b></em></p></div>' );


// 在n6元素外包裹嵌套的div元素：<div><p> <em><b></b></em>${#n5}</p></div>
// wrap()会从外层div依次往内部查找，以确定n5元素的所在位置
// wrap()将从外往内检查每层嵌套的第一个元素，如果该元素没有子元素或者第一个子元素不是Element节点，就停止向内查找
// 由于参数的'<p>'后面有空格(文本节点)，也就是说p元素的第一个子元素不是Element类型，因此直接将n6插入到p元素内部的末尾位置
$("#n6").wrap( '<div><p> <em><b></b></em></p></div>' );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-wrap-demo)

`wrap()`会将包裹元素的开始标记和结束标记分别置于匹配元素的两侧，**不会额外添加任何空白字符**，上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<div data_id="0"><p id="n1">
	<strong><span id="n2">span#n2</span></strong>    
</p></div>
<div data_id="1"><p id="n3">
	<form name="myForm"><input id="n4" type="text"></form>
</p></div>
<div><p><em><b><span id="n5">多层嵌套1</span></b></em></p></div>
<div><p> <em><b></b></em><span id="n6">多层嵌套2</span></p></div>
```

## 6、jQuery.replaceAll() 函数

`replaceAll()`函数用于**使用当前匹配元素替换掉所有的目标元素**。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.replaceAll( target )
```

参数

| 参数   | 描述                                                         |
| :----- | :----------------------------------------------------------- |
| target | String/Element/jQuery/Array类型被替换的目标元素，这些元素将被当前匹配元素替换掉。 |

如果参数`target`为字符串，则将其视作jQuery选择器。

返回值

`replaceAll()`函数的返回值为jQuery类型，返回表示替换内容的jQuery对象。

与被替换掉的节点关联的所有数据和事件处理器也将同时被移除。

*注意*：如果当前jQuery对象匹配的某个元素是页面上的元素，则该元素将从原来位置上消失，这相当于一个移动操作，而不是一个复制操作。

示例&说明

`replaceAll()`函数用于使用当前匹配元素替换掉所有的目标元素：

*JavaScript:*

```js
<p>段落文本1<span></span></p>
<p>段落文本2<span></span></p>

<script type="text/javascript">
$('<em></em>').replaceAll( "p" );
// 其返回值就是匹配替换内容(两个'<em></em>')的jQuery对象
</script>

<!--以下是jQuery代码执行后的html内容-->
<em></em>
<em></em>
```

请注意`replaceAll()`和[replaceWith()](https://codeplayer.vip/p/j7spf)函数之间的区别：

*JavaScript:*

```js
var $A = $("s1");
var $B = $("s2");


// 将$B替换成$A
$A.replaceAll( $B ); // 返回表示替换内容的jQuery对象( 匹配替换掉$B的所有$A元素 )
// 将$A替换成$B
$A.replaceWith( $B ); // 返回$A
```

请参考下面这段HTML代码(原HTML代码)：

*HTML:*

```html
<p id="n1">
	<span id="n2">foo</span>    
</p>
<p id="n3">
	<label id="n4">[label#n4]</label>
	<span id="n5">bar</span>
</p>
<div id="n6"></div>
```

以下jQuery示例代码，用于演示`replaceAll()`函数的具体用法：

*JavaScript:*

```js
// 用em元素替换掉所有的span元素
$('<em class="new">替代元素</em>').replaceAll( "span" );

// 用n4替换掉n6
// n4将从原位置上消失(替换到n6的位置)
$("#n4").replaceAll( $("#n6") );
```

以下是jQuery代码执行后的html内容(格式未作任何调整)：

*HTML:*

```html
<p id="n1">
	<em class="new">替代元素</em>    
</p>
<p id="n3">
	
	<em class="new">替代元素</em>
</p>
<label id="n4">[label#n4]</label>
```

## 7、jQuery.replaceWith() 函数

`replaceWith()`函数用于**==使用指定的元素替换每个匹配的元素==**。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.replaceWith( replacement )
```

参数

| 参数        | 描述                                               |
| :---------- | :------------------------------------------------- |
| replacement | String/Element/jQuery/Function类型用于替代的元素。 |

如果参数`replacement`为字符串，则将其视作html字符串。

jQuery 1.4 新增支持：参数`replacement`可以为函数。`replaceWith()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`replaceWith()`还会为函数传入两个参数：第一个参数就是当前元素在匹配元素中的索引，第二个参数就是该元素当前的内部html内容(innerHTML)。函数的返回值就是用于替换的内容(可以是html字符串、DOM元素、jQuery对象)。

返回值

`replaceWith()`函数的返回值为jQuery类型，返回当前jQuery对象本身(虽然其匹配的元素已从文档中被移除)。

与被替换掉的节点关联的所有数据和事件处理器也将同时被移除。

*注意*：如果`replacement`元素是当前页面中的元素，则该元素将从原位置上消失。这相当于一个移动操作，而不是一个复制操作。

示例&说明

`replaceWith()`函数用于在每个匹配元素的所有内容外部包裹指定的元素：

*JavaScript:*

```js
<p>段落文本1<span></span></p>
<p>段落文本2<span></span></p>

<script type="text/javascript">
$("p").replaceWith( '<em></em>' ); 
</script>

<!--以下是jQuery代码执行后的html内容-->
<em></em>
<em></em>
```

请注意`replaceWith()`和[replaceAll()](https://codeplayer.vip/p/j7spg)函数之间的区别：

*JavaScript:*

```js
var $A = $("s1");
var $B = $("s2");


// 将$A替换成$B
$A.replaceWith( $B ); // 返回$A
// 将$B替换成$A
$A.replaceAll( $B ); // 返回表示替换内容的jQuery对象( 匹配替换掉$B的所有$A元素 )
```

请参考下面这段HTML代码(原HTML代码)：

*HTML:*

```html
<p id="n1">
	<span id="n2">foo</span>    
</p>
<p id="n3">
	<label id="n4">[label#n4]</label>
	<span id="n5">bar</span>
</p>
<div id="n6"></div>
```

以下jQuery示例代码，用于演示`replaceWith()`函数的具体用法：

*JavaScript:*

```js
// 将所有span元素替换为指定的em元素
$("span").replaceWith( '<em class="new">替代元素</em>' );

// 将n6替换为n4
// n4将从原位置上消失
$("#n6").replaceWith( $("#n4") );

// 将所有p元素替换为div元素
$("p").replaceWith( function(i, innerHTML){
	return '<div class="thread-' + (i + 1) + '">' + innerHTML + '</div>';		
} );
```

以下是jQuery代码执行后的html内容(格式未作任何调整)：

*HTML:*

```html
<div class="thread-1">
    <em class="new">替代元素</em>    
</div>
<div class="thread-2">

    <em class="new">替代元素</em>
</div>
<label id="n4">[label#n4]</label>
```

## 8、jQuery.empty() 函数

`empty()`函数用于**==清空每个匹配元素内的所有内容==**。

`empty()`函数将会移除每个匹配元素的所有子节点(包括文本节点、注释节点等所有类型的节点)。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.empty( )
```

返回值

`empty()`函数的返回值为jQuery类型，返回当前jQuery对象本身(以便于进行链式风格的编程)。

示例&说明

`empty()`函数用于清空每个匹配元素内的所有内容：

*JavaScript:*

```js
<div><p>段落文本1<span></span></p></div>
<div><p>段落文本2<span></span></p></div>

<!--以上是jQuery代码执行前的html内容-->
<script type="text/javascript">
$("p").empty( ); 
</script>
<!--以下是jQuery代码执行后的html内容-->

<div><p></p></div>
<div><p></p></div>
```

`empty()`函数与[html()](https://codeplayer.vip/p/j7snu)函数具有以下等价代码：

*JavaScript:*

```js
$("selector").empty( );

// 等价于

$("selector").html("");
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<span id="n2">span#n2</span>    
</p>
<p id="n3">
	<label id="n4">label#n4</label>
	<span id="n5">span#n5</span>
</p>
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-empty-demo)

以下jQuery示例代码用于演示`empty()`函数的具体用法：

*JavaScript:*

```js
// 移除所有p元素中的所有子节点
$("p").empty( );
```

上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<p id="n1"></p>
<p id="n3"></p>
```

## 9、jQuery.remove() 函数

`remove()`函数用于**==从文档中移除匹配的元素==**。

你还可以使用选择器进一步缩小移除的范围，只移除当前匹配元素中符合指定选择器的部分元素。

与[detach()](https://codeplayer.vip/p/j7spi)相比，`remove()`函数会同时移除与元素关联绑定的附加数据( [data()](https://codeplayer.vip/p/j7snh)函数 )和事件处理器等(`detach()`会保留)。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.remove( [ selector ] )
```

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| selector | 可选/String类型指定的选择器字符串，用于筛选符合该选择器的元素。 |

如果没有指定`selector`参数，则移除当前匹配元素中的所有元素。

返回值

`remove()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

`remove()`函数用于从文档中移除匹配的元素：

*JavaScript:*

```js
<p>段落文本1<span>item1<i>line2<i></span></p>
<p>段落文本2<span>item2<i>line2<i></span></p>

<!--以上是jQuery代码执行前的html内容-->
<script type="text/javascript">
$("span").remove( );
</script>
<!--以下是jQuery代码执行后的html内容-->

<p>段落文本1</p>
<p>段落文本2</p>
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1" class="mark">
	<span id="n2">[span#n2]</span>    
</p>
<p id="n3" class="mark">
	<label id="n4" class="move">[label#n4]</label>
</p>
<p id="n5">
	段落内容
	<span id="n6">[span#n6]<span id="n7">[span#n7]</span></span>	
</p>
```

以下jQuery示例代码用于演示`remove()`函数的具体用法：

*JavaScript:*

```js
var $n6 = $("#n6");
// 移除n6元素
$n6.remove( );

var $p = $("p");
// 移除带有类名"mark"的p元素
var $removedP = $p.remove( ".mark" ); // $removedP === $p


// 将移除了的n6追加到body元素内的起始位置
// 虽然在前面n6已经从文档中被移除
// 但不会将其从jQuery对象中移除，因此我们还可以使用该jQuery对象，将n6再次放入文档中
$n6.prependTo( "body" );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-remove-demo)(其他代码请自行复制到演示页面运行)

上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<span id="n6">[span#n6]<span id="n7">[span#n7]</span></span>


<p id="n5">
	段落内容
		
</p>
```

`remove()`函数会移除文档中匹配的元素，但不会将匹配元素从jQuery对象中移除，不过`remove()`只会保留元素本身，其他的诸如元素所关联的附加数据和绑定事件等都会被移除。

请参考下面这段HTML代码：

*HTML:*

```html
<p id="n1">
	<input id="n2" type="button" value="按钮1" />
	<input id="n3" type="button" value="按钮2" />	
</p>
```

接着，我们为所有的按钮注册点击事件，然后移除元素n3，再将移除的n3重新追加到n1内部的末尾位置：

*JavaScript:*

```js
var $n3 = $("#n3");
$n3.data("myX", "附加数据");


document.writeln( $n3.data("myX") ); // 附加数据
$n3.trigger("click"); // 弹出提示框信息：按钮2

// 移除元素n3
$n3.remove();
// 将n3重新追加到n1内部的末尾
$n3.appendTo("#n1");

// 此时，n3的附加数据和绑定的点击事件都已被移除

document.writeln( $n3.data("myX") ); // undefined
$n3.trigger("click"); // 无任何事件响应
```

如果点击事件是直接在元素节点中以内联属性的形式注册的，则`remove()`**无法移除**这种形式的注册事件：

*HTML:*

```html
<input id="n3" type="button" value="按钮2" onclick="alert('无法移除该点击事件');" />
```

## 10、jQuery.detach() 函数

`detach()`函数用于**==从文档中移除匹配的元素==**。

你还可以使用选择器进一步缩小移除的范围，只移除当前匹配元素中符合指定选择器的部分元素。

与[remove()](https://codeplayer.vip/p/j7sph)相比，`detach()`函数**不会移除**与元素关联绑定的附加数据( [data()](https://codeplayer.vip/p/j7snh)函数 )和事件处理器等(`remove()`会移除)。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.detach( [ selector ] )
```

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| selector | 可选/String类型指定的选择器字符串，用于筛选符合该选择器的元素。 |

如果没有指定`selector`参数，则移除当前匹配元素中的所有元素。

返回值

`detach()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

`detach()`函数用于从文档中移除匹配的元素：

*JavaScript:*

```js
<p>段落文本1<span>item1<i>line2<i></span></p>
<p>段落文本2<span>item2<i>line2<i></span></p>

<!--以上是jQuery代码执行前的html内容-->
<script type="text/javascript">
$("span").detach( );
</script>
<!--以下是jQuery代码执行后的html内容-->

<p>段落文本1</p>
<p>段落文本2</p>
```

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1" class="mark">
	<span id="n2">[span#n2]</span>    
</p>
<p id="n3" class="mark">
	<label id="n4" class="move">[label#n4]</label>
</p>
<p id="n5">
	段落内容
	<span id="n6">[span#n6]<span id="n7">[span#n7]</span></span>	
</p>
```

以下jQuery示例代码用于演示`detach()`函数的具体用法：

*JavaScript:*

```js
var $n6 = $("#n6");
// 移除n6元素
$n6.detach( );

var $p = $("p");
// 移除带有类名"mark"的p元素
var $detachedP = $p.detach( ".mark" ); // $detachedP === $p


// 将移除了的n6追加到body元素内的起始位置
// 虽然在前面n6已经从文档中被移除
// 但不会将其从jQuery对象中移除，因此我们还可以使用该jQuery对象，将n6再次放入文档中
$n6.prependTo( "body" );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-detach-demo)(其他代码请自行复制到演示页面运行)

上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<span id="n6">[span#n6]<span id="n7">[span#n7]</span></span>


<p id="n5">
	段落内容
		
</p>
```

`detach()`函数会移除文档中匹配的元素，但不会将匹配元素从jQuery对象中移除，而且`detach()`会保留元素所关联的附加数据和绑定事件等。

请参考下面这段HTML代码：

*HTML:*

```html
<p id="n1">
	<input id="n2" type="button" value="按钮1" />
	<input id="n3" type="button" value="按钮2" />	
</p>
```

接着，我们为所有的按钮注册点击事件，然后移除元素n3，再将移除的n3重新追加到n1内部的末尾位置：

*JavaScript:*

```js
var $n3 = $("#n3");
$n3.data("myX", "附加数据");


document.writeln( $n3.data("myX") ); // 附加数据
$n3.trigger("click"); // 弹出提示框信息：按钮2

// 移除元素n3
$n3.detach();
// 移除之后，仍然可以获取附加数据并触发点击事件
// document.writeln( $n3.data("myX") ); // 附加数据
// $n3.trigger("click"); // 弹出提示框信息：按钮2

// 将n3重新追加到n1内部的末尾
$n3.appendTo("#n1");

// 此时，n3的附加数据和绑定的点击事件仍然存在

document.writeln( $n3.data("myX") ); // 附加数据
$n3.trigger("click"); // 弹出提示框信息：按钮2
```

## 11、jQuery.clone() 函数

`clone()`函数用于**==克隆当前匹配元素集合的一个副本==**，并以jQuery对象的形式返回。你也可以简单地理解为：克隆当前jQuery对象。

你还可以指定是否复制这些匹配元素(甚至它们的子元素)的附加数据( [data()](https://codeplayer.vip/p/j7snh)函数 )和绑定事件。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.clone( withDataAndEvents [, deepWithDataAndEvents ] )
```

参数

| 参数                  | 描述                                                         |
| :-------------------- | :----------------------------------------------------------- |
| withDataAndEvents     | 可选/Boolean类型是否同时复制元素的附加数据和绑定事件，默认为`false`。 |
| deepWithDataAndEvents | 可选/Boolean类型是否同时复制元素的所有子元素的附加数据和绑定事件，默认值即为参数`withDataAndEvents`的值。 |

`clone()`主要用于克隆当前jQuery对象的一个副本。

jQuery 1.5 新增支持：clone()支持第二个参数`deepWithDataAndEvents`。该参数指示是否同时复制被克隆元素的所有子元素的附加数据和绑定事件。

> *注意*：
> 1、在jQuery 1.4之前， `clone()`函数只额外复制元素的绑定事件，从 1.4版本开始，才开始支持复制元素的附加数据。
>
> 2、 1.5.0版本时(只有1.5.0)，参数 `withDataAndEvents`的默认值被错误地设定为 `true`，从 1.5.1开始，其默认值才被改回 `false`。

返回值

`clone()`函数的返回值为jQuery类型，返回当前jQuery对象的一个克隆副本。

*注意*：出于性能原因考虑，`clone()`函数不会复制某些表单元素的动态，例如用户在<textarea>输入的内容、用户在<select>中选择的选项。不过<input>元素的动态将会被复制，例如用户在text中输入的内容、用户对checkbox的选中状态。

示例&说明

`clone()`函数用于克隆当前jQuery对象。请参考下面这段HTML代码为例：

*HTML:*

```html
<p id="n1">
	<input id="n2" type="button" value="按钮1" />
	<input id="n3" type="button" value="按钮2" />
</p>
```

以下jQuery示例代码用于演示`clone()`函数的具体用法：

*JavaScript:*

```js
// 当前jQuery版本：1.11.1

$(":button").click( function(){
	document.writeln( this.value );
} );
var $n2 = $("#n2");
$n2.data("myData", "附加数据");

//没有克隆附加数据和绑定事件
var $clonedN2 = $n2.clone(); // 两个参数均默认为false
document.writeln( $clonedN2.data("myData") ); // undefined
$clonedN2.trigger("click"); // (没有绑定的点击事件，无响应输出)

//同时克隆附加数据和绑定事件
var $clonedN2WithCopy = $n2.clone( true ); // 两个参数：true、true(第二个参数不设置，默认为第一个参数的值)
document.writeln( $clonedN2WithCopy.data("myData") ); // 附加数据
$clonedN2WithCopy.trigger("click"); // 按钮1
```

# 六、CSS操作

## 0、CSS操作一览表

> *版本说明*：如果"版本"列的版本号带有删除线(例如： ~~1.8~~)，表示从该版本开始，此方法 **已过时**。如果版本号带有删除线，并且为红色(例如： ~~1.9~~)，表示从该版本开始，此方法已 **被移除**。

*注意*：
如果当前jQuery对象匹配多个DOM元素，那么我们执行该对象的下列方法时：如果当前执行的是"写"操作，则作用于每一个匹配的元素；如果当前执行的是"读"操作，则只作用于第一个匹配的元素。
以使用`attr()`方法为例：如果我们用它来设置属性，它将会为匹配的每一个元素都设置属性；如果用它来读取属性，则它只会获取第一个匹配元素对应的属性值。

如果当前jQuery对象不匹配任何元素，执行以下方法也不会报错。jQuery会根据合理的逻辑来采取不同的操作策略。例如：对于属性、CSS而言，设置操作将不会执行，获取操作将视具体情况返回undefined、null、空字符串等值。对于文档内容处理而言，jQuery会视具体情况采取不处理、或将其当作空的内容来处理等措施。

| CSS操作——操作文档节点的样式属性。               |       |                                                              |
| ----------------------------------------------- | ----- | ------------------------------------------------------------ |
| [css()](https://codeplayer.vip/p/j7spk)         | 1.0   | 设置或返回元素的CSS属性。                                    |
| jQuery.cssHooks                                 | 1.4.3 | 全局属性用于设置或获取jQuery操作CSS属性的钩子。              |
| [offset()](https://codeplayer.vip/p/j7spl)      | 1.2   | 获取鼠标相对于当前文档的坐标。                               |
| [position()](https://codeplayer.vip/p/j7spm)    | 1.2   | 获取当前元素相对于离它最近的拥有定位的祖辈元素的坐标。       |
| [scrollTop()](https://codeplayer.vip/p/j7spn)   | 1.2.6 | 设置或返回当前元素相对于垂直滚动条顶部的偏移                 |
| [scrollLeft()](https://codeplayer.vip/p/j7spo)  | 1.2.6 | 设置或返回当前元素相对于水平滚动条最左侧的偏移               |
| [height()](https://codeplayer.vip/p/j7spp)      | 1.0   | 设置或返回当前元素的高度值(不包括内边距、边框、外边距)。     |
| [width()](https://codeplayer.vip/p/j7spq)       | 1.0   | 设置或返回当前元素的宽度值(不包括内边距、边框、外边距)。     |
| [innerHeight()](https://codeplayer.vip/p/j7spr) | 1.2.6 | 设置或返回当前元素的内高度(包括内边距)。                     |
| [innerWidth()](https://codeplayer.vip/p/j7sps)  | 1.2.6 | 设置或返回当前元素的内宽度(包括内边距)。                     |
| [outerHeight()](https://codeplayer.vip/p/j7spt) | 1.2.6 | 设置或返回当前元素的外高度(包括内边距、边框，以及可选的外边距)。 |
| [outerWidth()](https://codeplayer.vip/p/j7spu)  | 1.2.6 | 设置或返回当前元素的外宽度(包括内边距、边框，以及可选的外边距)。 |

## 1、jQuery.css() 函数

`css()`函数用于**==设置或返回当前jQuery对象所匹配的元素的css样式属性值==**。

该函数属于`jQuery`对象(实例)。如果需要删除指定的css属性，请使用该函数将其值设为空字符串("")。

语法

`css()`函数有以下两种用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.css( propertyName [, value ] )
```

设置或返回指定css属性`propertyName`的值。

- 如果指定了`value`参数，则表示设置css属性`propertyName`的值为`value`；
- 如果没有指定`value`参数，则表示返回css属性`propertyName`的值。

**用法二**：

*JavaScript:*

```js
jQueryObject.css( object )
```

以对象形式同时设置任意多个属性的值。对象`object`的每个属性对应`propertyName`，属性的值对应`value`。*
*

*注意*：
1、如果省略了`value`参数，则表示获取属性值；如果指定了该参数，则表示设置属性值。
2、`css()`函数的所有"设置"操作针对的是当前jQuery对象所匹配的每一个元素；所有"读取"操作只针对第一个匹配的元素。

参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数         | 描述                                                         |
| :----------- | :----------------------------------------------------------- |
| propertyName | String/Array类型指定的css属性名称(用于设置或返回)，或者css属性名称数组(仅用于返回)。 |
| value        | 可选/String/Number/Function类型指定的属性值，或返回属性值的函数。 |
| object       | Object类型指定的对象，用于封装多个键值对，同时设置多项属性。 |

jQuery 1.4 新增支持：参数`value`可以是函数，`css()`将根据匹配的所有元素遍历执行该函数，函数中的`this`指针将指向对应的DOM元素。`css()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素css属性`propertyName`当前的值。函数的返回值就是为该元素的css属性`propertyName`设置的值。

jQuery 1.9 新增支持：如果是"获取"操作(仅限"获取"操作)，参数`propertyName`还可以是多个css属性名称组成的数组，`css()`将以对象形式返回多个css属性(对象的属性名称对应css属性名称，属性值对应css属性值)。

返回值

`css()`函数的返回值是任意类型，返回值的类型取决于当前`css()`函数执行的是"设置"操作还是"读取"操作。

如果`css()`函数执行的是"设置"操作，则返回当前jQuery对象本身；如果是"读取"操作，则返回读取到的属性值。

如果当前jQuery对象匹配多个元素，返回属性值时，`css()`函数只以其中第一个匹配的元素为准。如果该元素没有指定的属性，则返回`undefined`。

注意事项

1、如果参数`value`为空字符串("")，则表示删除该css属性。

2、对于多个单词构成的css属性，你可以使用其css格式("-")或者DOM格式(驼峰式)，jQuery都能理解。例如`background-color`，你可以将`propertyName`设为`background-color`或`backgroundColor`。建议优先以驼峰式来获取(jQuery底层也是通过DOM来获取的，DOM元素的属性均以驼峰式命名)。

3、有些时候获取到的css属性值与你在样式表中设置的值并不完全相同。例如：某些表示尺寸的属性值，你可能在样式表中设置的单位是em、px、ex或者%，但jQuery获取的是经过浏览器计算后css属性值，其单位多数情况下为像素。此外，不同浏览器对于颜色(`color`)属性值的文本表示也不一致，以white为例，浏览器可能返回white、#FFF、#ffffff、rgb(255,255,255)等，当然它们在逻辑上都表示白色。

4、对于一些速写的css属性，例如margin、padding、background、border。尽管某些浏览器提供了此功能，但它的结果是无法保证的，有些浏览器也并不支持。以margin为例，你可能需要通过`css("marginTop")`、`css("marginRight")`等方式来分别获取。从jQuery 1.9开始，你可以传入一个数组来获取多个css属性(以对象形式返回)。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<p id="n1" style="font-size: 16px; font-weight:bold; color: #333; margin: 10px 5px;">CodePlayer</p>
<p id="n2" style="font-size: 14px; font-weight:bold; color: #aacd12; padding: 5px ; border: 1px solid #000;">专注于编程开发技术分享</p>
```

我们编写如下jQuery代码：

*JavaScript:*

```js
var $n1 = $("#n1");
var $n2 = $("#n2");

document.writeln( $n1.css("fontSize" /* 或者"font-size" */ ) );
document.writeln( $n1.css("margin") ); // Chrome：10px 5px | FireFox和IE下无输出
document.writeln( $n1.css("marginTop") ); // 10px (所有浏览器均支持)
document.writeln( $n1.css("marginLeft") ); // 5px (所有浏览器均支持)

// 取消n1的粗体
$n1.css("fontWeight", "normal");

// 更改n2的背景色和字体
$n2.css( { backgroundColor: "#efefef", "font-family": '"Microsoft Yahei"' } );

var styleObj = $n2.css( ["paddingTop", "paddingRight", "paddingBottom", "paddingLeft"] );
document.writeln( styleObj.paddingTop ); // 5px
document.writeln( styleObj.paddingRight ); // 5px

// 删除n2的border属性
$n2.css("border", "");

// 更改所有p元素的font-weight属性
// 如果是粗体就还原，不是粗体就加粗
$("p").css("fontWeight", function(index, value){
	// 不同浏览器的计算取值可能有差异
	return value == "bold" || value == "700" ? "normal" : "bold";
});
```

## 2、jQuery.offset() 函数

`offset()`函数用于==**设置或返回当前匹配元素相对于当前文档的偏移**，也就是相对于当前文档的坐标。**该函数只对可见元素有效**==。

该函数返回一个坐标对象(Object)，该对象有一个`left`属性和`top`属性。属性值均为数字，它们都以像素(px)为单位。

与[position()](https://codeplayer.vip/p/j7spm)不同的是：`offset()`返回的是相对于当前文档的坐标，`position()`返回的是相对于其定位的祖辈元素的坐标。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.offset( [ coordinates ] )
```

*注意*：
1、如果省略了`coordinates`参数，则表示获取偏移位置；如果指定了该参数，则表示设置偏移位置。2、`offset()`函数的"设置"操作针对的是当前jQuery对象所匹配的每一个元素；"读取"操作只针对第一个匹配的元素。

参数

| 参数        | 描述                                                     |
| :---------- | :------------------------------------------------------- |
| coordinates | 可选/Object类型用于设置的坐标对象(应具有left和top属性)。 |

jQuery 1.4 新增支持：`offset()`支持通过传入`coordinates`参数来设置匹配元素的坐标。

在1.4之前，`offset()`只用于获取第一个匹配元素的坐标。从1.4开始，`offset()`还可用于设置所有匹配元素的坐标。参数`coordinates`即表示需要设置的坐标值。

参数`coordinates`应该是一个具备`left`和`top`属性的对象。

参数`coordinates`还可以是函数，则`offset()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`offset()`还会为函数传入两个参数：第一个参数就是当前元素在匹配元素中的索引，第二个参数就是该元素当前的坐标对象。函数的返回值就是需要设置的坐标对象。

返回值

`offset()`函数的返回值为Object类型，返回值的类型取决于`offset()`函数当前执行的是"设置"操作还是"读取"操作。

如果`offset()`函数执行的是"设置"操作，则返回当前jQuery对象本身；如果是"读取"操作，则返回第一个匹配元素相对于当前文档的坐标对象。

如果当前jQuery对象匹配多个元素，返回坐标时，`offset()`函数只以其中第一个匹配的元素为准。如果没有匹配的元素，则返回`undefined`。

`offset()`中的坐标参考系是以当前文档的左上角为原点(0,0)，向右为正，向下为正。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<br>
<br>
<p id="n1">CodePlayer</p>
<p id="n2" class="meta" left="20" top="50" >专注于编程开发技术分享</p>
<p id="n3" class="meta" left="20" top="100">https://codeplayer.vip</p>
```

以下jQuery示例代码用于演示`offset()`函数的具体用法：

*JavaScript:*

```js
var $n1 = $("#n1");
// 输出n1的当前坐标
var coord = $n1.offset();
alert( "当前坐标：(" + coord.left + ", " + coord.top + ")" ); // 当前坐标：(8, 60)

// 设置n1的坐标为(0, 0)
var offset = $n1.offset( {top: 0, left: 0});


var $meta_p = $("p.meta");

// 将所有带类名meta的p元素相对当前位置进行left和top属性指定的偏移。
$meta_p.offset( function(index, coord){
	var $me = $(this);
	var left = $me.attr("left"), top = $me.attr("top");
	left = isNaN( left ) ? 0 : parseInt(left, 10);
	top = isNaN( top ) ? 0 : parseInt(top, 10);
	return { "left": coord.left + left, "top": coord.top + top  };	
} );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-offset-demo)

上述代码执行后的完整html代码如下(格式未作任何调整)：

*HTML:*

```html
<br>
<br>
<p id="n1" style="position: relative; top: -60px; left: -8px;">CodePlayer</p>
<p id="n2" class="meta" left="20" top="50" style="position: relative; top: 50px; left: 20px;">专注于编程开发技术分享</p>
<p id="n3" class="meta" left="20" top="100" style="position: relative; top: 100px; left: 20px;">https://codeplayer.vip</p>
</body>
```

## 3、jQuery.position() 函数

`position()`函数用于==**返回当前匹配元素相对于其被定位的祖辈元素的偏移**，也就是相对于被定位的祖辈元素的坐标。**该函数只对可见元素有效**。==

所谓"被定位的元素"，就是元素的CSS `position`属性值为`absolute`、`relative`或`fixed`(只要不是默认的`static`即可)。

该函数返回一个坐标对象，该对象有一个`left`属性和`top`属性。属性值均为数字，它们都以像素(px)为单位。

与[offset()](https://codeplayer.vip/p/j7spl)不同的是：`position()`返回的是相对于被定位的祖辈元素的坐标，`offset()`返回的是相对于当前文档的坐标。此外，`position()`函数无法用于设置操作。如果当前元素的祖辈元素全部都是默认定位(static)，那么该函数返回的偏移位置与`offset()`函数相同。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.position( )
```

返回值

`position()`函数的返回值为Object类型，返回一个相对于离它最近的"被定位的"祖辈元素的偏移坐标对象，该对象具有left和top属性。

如果当前jQuery对象匹配多个元素，返回坐标时，`position()`函数只以其中第一个匹配的元素为准。如果没有匹配的元素，则返回`undefined`。

`position()`中的坐标参考系是以被定位的祖辈元素的左上角为原点(0,0)，向右为正，向下为正。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<br>
<br>
<p id="n1"><span id="n2">专注于编程开发技术分享</span></p>
```

以下jQuery示例代码用于演示`position()`函数和`offset()`函数的用法：

*JavaScript:*

```js
var $n2 = $("#n2");

// 输出n2的偏移坐标

var pos = $n2.position();
document.writeln( "n2的position()偏移坐标：(" + pos.left + ", " + pos.top + ")" ); // n2的position()偏移坐标：(8, 60)

var coord = $n2.offset();
document.writeln( "n2的offset()的偏移坐标：(" + coord.left + ", " + coord.top + ")" ); // n2的offset()的偏移坐标：(8, 60)
```



从上述jQuery的运行结果可知，`position()`并不是获取相对于其父元素的偏移位置。如果n2的祖辈元素全部为默认定位，则`position()`返回的偏移位置和`offset()`函数一致。

下面，我们将上述HTML代码中的n1加上相对定位(relative)：

*HTML:*

```html
<br>
<br>
<p id="n1" style="position: relative;" ><span id="n2">专注于编程开发技术分享</span></p>
```



然后，我们重新执行上述jQuery代码，可以看到以下结果：

*JavaScript:*

```js
var $n2 = $("#n2");

// 输出n2的偏移坐标

var pos = $n2.position();
document.writeln( "n2的position()偏移坐标：(" + pos.left + ", " + pos.top + ")" ); // n2的position()偏移坐标：(0, 0)

var coord = $n2.offset();
document.writeln( "n2的offset()的偏移坐标：(" + coord.left + ", " + coord.top + ")" ); // n2的offset()的偏移坐标：(8, 60)
```

此时，在n2的祖辈元素中，n1是离n2最近的定位的祖辈元素(这里是relative，absolute、fixed也是如此)，因此`position()`返回n2相对于n1的偏移位置。

## 4、jQuery.scrollLeft() 函数

`scrollLeft()`函数用于==**设置或返回当前匹配元素相对于水平滚动条左侧的偏移**。==

当一个元素的实际宽度超过其显示区域的宽度时，在一定的设置下，浏览器会为该元素显示相应的水平滚动条。此时，`scrollLeft()`返回的就是该元素在可见的滚动区域左侧被隐藏部分的宽度(单位：像素)。

如果水平滚动条在最左侧(也就是可见区域左侧没有被隐藏的内容)，或者当前元素是不可水平滚动的，那么`scrollLeft()`将返回0。

该函数属于`jQuery`对象(实例)，并且对可见的和隐藏的元素均有效。

语法

jQuery 1.2.6 新增该函数。

*JavaScript:*

```js
jQueryObject.scrollLeft( [ value ] )
```

*注意*：
1、如果省略了`value`参数，则表示返回偏移值；如果指定了该参数，则表示设置偏移值。
2、`scrollLeft()`函数的"设置"操作针对的是当前jQuery对象所匹配的每一个元素；"读取"操作只针对第一个匹配的元素。

参数

| 参数  | 描述                              |
| :---- | :-------------------------------- |
| value | 可选/Number类型用于设置的偏移值。 |

返回值

`scrollLeft()`函数的返回值为Number/jQuery类型，返回值的类型取决于`scrollLeft()`函数当前执行的是"设置"操作还是"读取"操作。

如果`scrollLeft()`函数执行的是"设置"操作，则返回当前jQuery对象本身；如果是"读取"操作，则返回第一个匹配元素相对于水平滚动条最左端的偏移。

如果当前jQuery对象匹配多个元素，返回坐标时，`scrollLeft()`函数只以其中第一个匹配的元素为准。如果没有匹配的元素，则返回`null`。

示例&说明

以下面这段HTML代码为例(限定宽度，强制该元素内容不换行)：

*HTML:*

```html
<div id="content" style="width:200px; height: 100px; overflow:auto; white-space: nowrap;">
CodePlayer 专注于编程开发技术分享  CodePlayer 专注于编程开发技术分享 CodePlayer 专注于编程开发技术分享<br>
</div>
<input id="btn" type="button" value="点击" >
<div id="msg"></div>
```

以下jQuery示例代码用于演示`scrollLeft()`函数的具体用法：

*JavaScript:*

```js
var $content = $("#content");
var $btn = $("#btn");
var $msg = $("#msg");

$btn.click( function(){
	$msg.html ( "content的scrollLeft：" + $content.scrollLeft() );	
} );

// 设置显示区域左侧隐藏99像素宽度的内容
$content.scrollLeft( 99 );
```

## 5、jQuery.height() 函数

`height()`函数用于**==设置或返回当前匹配元素的高度==**。

==该高度值**不包括**元素的外边距(margin)、内边距(padding)、边框(border)等部分的高度。==

如果你要获取包括上述某部分在内的高度，请使用[innerHeight()](https://codeplayer.vip/p/j7spr)和[outerHeight()](https://codeplayer.vip/p/j7spt)，你可以点此查看[三者之间的区别](https://codeplayer.vip/p/j7spv)。

该函数属于`jQuery`对象(实例)，并且对不可见的元素依然有效。

语法

*JavaScript:*

```js
jQueryObject.height( [ value ] )
```

*注意*：
1、如果省略了`value`参数，则表示获取高度；如果指定了该参数，则表示设置高度。
2、`height()`函数的"设置"操作针对的是当前jQuery对象所匹配的每一个元素；"读取"操作只针对第一个匹配的元素。

参数

| 参数  | 描述                              |
| :---- | :-------------------------------- |
| value | 可选/Number类型用于设置的高度值。 |

jQuery 1.4.1 新增支持：参数`value`可以为函数，则`height()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`height()`还会为函数传入两个参数：第一个参数就是当前元素在匹配元素中的索引，第二个参数就是该元素当前的高度值。函数的返回值就是需要设置的高度值。

返回值

`height()`函数的返回值为jQuery/Number类型，返回值的类型取决于`height()`函数当前执行的是"设置"操作还是"读取"操作。

如果`height()`函数执行的是"设置"操作，则返回当前jQuery对象本身；如果是"读取"操作，则返回第一个匹配元素的高度值。



如果当前jQuery对象匹配多个元素，返回高度时，`height()`函数只以其中第一个匹配的元素为准。如果没有匹配的元素，则返回`null`。

示例&说明

`height()`函数和[css("height")](https://codeplayer.vip/p/j7spk)作用相似，只不过`height()`的高度值不带单位(单位为像素)。

*JavaScript:*

```js
$(element).height(); // 返回数字，例如：100
$(element).css("height"); // 返回字符串，例如："100px"
```

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1" style="padding: 10px;"></div>
<div id="n2" style="height: 100px;"></div>
```

以下jQuery示例代码用于演示`height()`函数的具体用法：

*JavaScript:*

```js
var $n1 = $("#n1");
var $n2 = $("#n2");

document.writeln( $n1.height() ); // 0
document.writeln( $n2.height() ); // 100

var $divs = $("div");
// 如果匹配多个元素，只返回第一个元素的height
document.writeln( $divs.height() ); // 0

// 设置n1的height为20px
$n1.height( 20 );

// 设置所有div元素的height不能小于50px(小于50的设为50，其它不变)
$divs.height( function(index, height){
	return Math.max(height, 50);		
} );
```

该函数也可用于获取`window`和`document`对象的高度。

*JavaScript:*

```js
// 返回window的height(浏览器视口的高度)
$(window).height();

// 返回document的height(HTML文档的高度)
$(document).height();
```

## 6、jQuery.innerHeight() 函数

`innerHeight()`函数用于**==设置或返回当前匹配元素的内高度==**。

===内高度包括元素的内边距(padding)，但**不包括**外边距(margin)、边框(border)等部分的高度。===

如果你要获取其它情况的高度，请使用[height()](https://codeplayer.vip/p/j7spp)和[outerHeight()](https://codeplayer.vip/p/j7spt)，你可以点此查看[三者之间的区别](https://codeplayer.vip/p/j7spv)。

该函数属于`jQuery`对象(实例)，并且对不可见的元素依然有效。

语法

jQuery 1.2.6 新增该函数。

*JavaScript:*

```js
jQueryObject.innerHeight( [ value ] )
```

*注意*：
1、如果省略了`value`参数，则表示获取内高度；如果指定了该参数，则表示设置内高度。
2、`innerHeight()`函数的"设置"操作针对的是当前jQuery对象所匹配的每一个元素；"读取"操作只针对第一个匹配的元素。

参数

| 参数  | 描述                                |
| :---- | :---------------------------------- |
| value | 可选/Number类型用于设置的内高度值。 |

1.8.0之前，`innerHeight()`只用于获取内高度(不接受任何参数)，无法设置内高度值。

jQuery 1.8.0 新增支持：`innerHeight()`函数支持参数`value`，用于设置每个匹配元素的内高度。

参数`value`还可以为函数，则`innerHeight()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。



`innerHeight()`还会为函数传入两个参数：第一个参数就是当前元素在匹配元素中的索引，第二个参数就是该元素当前的内高度。函数的返回值就是需要设置的内高度。

返回值

`innerHeight()`函数的返回值为jQuery/Number类型，返回值的类型取决于`innerHeight()`函数当前执行的是"设置"操作还是"读取"操作。

如果`innerHeight()`函数执行的是"设置"操作，则返回当前jQuery对象本身；如果是"读取"操作，则返回第一个匹配元素的内高度。

如果当前jQuery对象匹配多个元素，返回内高度时，`innerHeight()`函数只以其中第一个匹配的元素为准。如果没有匹配的元素，则返回`null`。

`innerHeight()`不适用于`window`和`document`，请使用[height()](https://codeplayer.vip/p/j7spp)替代。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1" style="padding: 10px; height: 100px; border: 1px solid #000;"></div>
<div id="n2" style="height: 150px; background: #999;"></div>
```

以下jQuery示例代码用于演示`innerHeight()`函数的具体用法：

*JavaScript:*

```js
var $n1 = $("#n1");
var $n2 = $("#n2");

document.writeln( $n1.innerHeight() ); // 120
document.writeln( $n2.innerHeight() ); // 150

var $divs = $("div");
// 如果匹配多个元素，只返回第一个元素的innerHeight
document.writeln( $divs.innerHeight() ); // 120

/* *****以下jQuery代码仅限于 1.8.0及之后版本***** */


// 设置所有div元素的innerHeight不能小于200px(小于200的设为200，其它保持不变)
$divs.innerHeight( function(index, innerHeight){
	return Math.max(innerHeight, 200);		
} );

// 设置n1的innerHeight为20px
$n1.innerHeight( 20 );
```

## 7、jQuery.outerHeight() 函数

`outerHeight()`函数用于**==获取当前匹配元素的外高度==**。

==外高度默认包括元素的内边距(padding)、边框(border)，但**不包括**外边距(margin)部分的高度。你也可以指定参数为`true`，以包括外边距(margin)部分的高度。==

如果你要获取其它情况的高度，请使用[height()](https://codeplayer.vip/p/j7spp)和[innerHeight()](https://codeplayer.vip/p/j7spr)，你可以点此查看[三者之间的区别](https://codeplayer.vip/p/j7spv)。

该函数属于`jQuery`对象(实例)，并且对不可见的元素依然有效。

语法

jQuery 1.2.6 新增该函数。

*JavaScript:*

```js
jQueryObject.outerHeight( [ includeMargin ] )
```

*注意*：如果当前jQuery对象匹配多个元素，则只返回第一个匹配的元素的外高度。

参数

| 参数          | 描述                                                         |
| :------------ | :----------------------------------------------------------- |
| includeMargin | 可选/Boolean类型指示是否包含外边距部分的高度，默认为`false`。 |

返回值

`outerHeight()`函数的返回值为Number类型，返回第一个匹配元素的外高度。

如果当前jQuery对象匹配多个元素，返回外高度时，`outerHeight()`函数只以其中第一个匹配的元素为准。如果没有匹配的元素，则返回`null`。

`outerHeight()`不适用于`window`和`document`，请使用[height()](https://codeplayer.vip/p/j7spp)替代。

示例&说明

以下面这段HTML代码为例：

*HTML:*

```html
<div id="n1" style="margin:5px; padding: 10px; height: 100px; border: 1px solid #000;"></div>
<div id="n2" style="height: 150px; background: #999;"></div>
```

以下jQuery示例代码用于演示`outerHeight()`函数的具体用法：

*JavaScript:*

```js
var $n1 = $("#n1");
var $n2 = $("#n2");

// outerHeight() = height(100) + padding(10*2) + border(1*2) = 122 
document.writeln( $n1.outerHeight() ); // 122
document.writeln( $n2.outerHeight() ); // 150

var $divs = $("div");
// 如果匹配多个元素，只返回第一个元素的outerHeight
document.writeln( $divs.outerHeight() ); // 122


//outerHeight(true) = height(100) + padding(10*2) + border(1*2) + margin(5*2) = 132 
document.writeln( $n1.outerHeight(true) ); // 132
document.writeln( $n2.outerHeight(true) ); // 150
```

## 8、height()、innerHeight()、outerHeight()函数的区别

在jQuery中，获取元素高度的函数有3个，它们分别是[height()](https://codeplayer.vip/p/j7spp)、 [innerHeight()](https://codeplayer.vip/p/j7spr)、 [outerHeight()](https://codeplayer.vip/p/j7spt)。

与此相对应的是，获取元素宽度的函数也有3个，它们分别是[width()](https://codeplayer.vip/p/j7spq)、 [innerWidth()](https://codeplayer.vip/p/j7sps)、 [outerWidth()](https://codeplayer.vip/p/j7spu)。

在这里，我们以`height()`、`innerHeight()`、`outerHeight()`3个函数为例，来详细介绍它们之间的区别。

下面我们以元素element的盒模型为例来介绍它们之间的区别。

| 函数                | 高度范围                     | jQuery版本 | 支持写操作 |
| :------------------ | :--------------------------- | :--------- | :--------- |
| `height()`          | height                       | 1.0+       | 1.0+       |
| `innerHeight()`     | height + padding             | 1.2.6+     | 1.8.0+     |
| `outerHeight()`     | height + padding + border    | 1.2.6+     | *否*       |
| `outerHeight(true)` | height+padding+border+margin | 1.2.6+     | *否*       |



> 1、 只有 `height()`函数可用于 `window`或 `document`对象。
>
> 2、 "支持写操作"表示该函数可以为元素设置高度值。
>
> 3、 1.4.1+ `height()`新增支持参数为函数(之前只支持数值)。
>
> 4、 1.8.0+ `innerHeight()`支持参数为数值或函数。

现在，我们参考以下HTML + jQuery示例代码：[运行代码

*JavaScript:*

```js
<div id="element" style="margin:5px; padding:10px; width:100px; height:100px; border:1px solid #000;"></div>


<script type="text/javascript">
var $ele = $("#element");

// height() = height(100) = 100
document.writeln( $ele.height() ); // 100

// innerHeight() = height(100) + padding(10*2)= 120 
document.writeln( $ele.innerHeight() ); // 120

// outerHeight() = height(100) + padding(10*2) + border(1*2) = 122 
document.writeln( $ele.outerHeight() ); // 122

// outerHeight(true) = height(100) + padding(10*2) + border(1*2) + margin(5*2) = 132 
document.writeln( $ele.outerHeight(true) ); // 132
</script>
```

# 七、事件

## 0、jQuery的事件方法

本文列出了jQuery中几乎所有的**事件方法**。使用这些方法可以非常简单方便地对文档中的指定元素的对应事件绑定一个或多个事件处理函数。

例如：

- 为元素的click、focus、change、submit等事件绑定一个或多个处理函数。
- 手动触发元素的指定事件。
- 阻止事件触发默认行为，或停止事件在DOM树中的冒泡。
- 解除指定元素上的事件绑定。

> *版本说明*：如果"版本"列的版本号带有删除线(例如： ~~1.8~~)，表示从该版本开始，此方法 **已过时**。如果版本号带有删除线，并且为红色(例如： ~~1.9~~)，表示从该版本开始，此方法已 **被移除**。

jQuery对象的核心事件方法

核心事件函数，主要用于为元素的任意事件(包括自定义事件)**添加**、**取消**、**触发**绑定的一个或多个事件处理函数。

| 方法                                               | 版本                | 描述                                                         |
| :------------------------------------------------- | :------------------ | :----------------------------------------------------------- |
| [bind()](https://codeplayer.vip/p/j7sqs)           | 1.0                 | 为元素的任意事件绑定事件处理函数。                           |
| [one()](https://codeplayer.vip/p/j7squ)            | 1.1                 | 为元素(或后代元素)的任意事件绑定一次性的事件处理函数。       |
| [live()](https://codeplayer.vip/p/j7sqq)           | 1.3~~~1.7~~~~~1.9~~ | 为元素(或后代元素)的任意事件绑定事件处理函数。               |
| [delegate()](https://codeplayer.vip/p/j7sqn)       | 1.4.2               | 为元素(或后代元素)的任意事件绑定事件处理函数。               |
| [on()](https://codeplayer.vip/p/j7sq1)             | 1.7                 | 为元素(或后代元素)的任意事件绑定事件处理函数。               |
| [unbind()](https://codeplayer.vip/p/j7sqt)         | 1.0                 | bind()的逆操作，解除元素任意事件绑定的处理函数。             |
| [die()](https://codeplayer.vip/p/j7sqr)            | 1.3~~~1.7~~~~~1.9~~ | live()的逆操作，解除元素(或后代元素)任意事件绑定的处理函数。 |
| [undelegate()](https://codeplayer.vip/p/j7sqp)     | 1.4.2               | delegate()的逆操作，解除元素(或后代元素)任意事件绑定的处理函数。 |
| [off()](https://codeplayer.vip/p/j7sqo)            | 1.7                 | on()的逆操作，解除元素(或后代元素)任意事件绑定的处理函数。   |
| [trigger()](https://codeplayer.vip/p/j7sqv)        | 1.0                 | 手动触发元素上的任意事件。                                   |
| [triggerHandler()](https://codeplayer.vip/p/j7sr0) | 1.2                 | 手动触发元素上的任意事件，但不会触发元素的默认事件行为，也不支持事件冒泡。 |

jQuery对象的常规事件方法

常规事件函数，主要用于为元素的指定事件**添加**、**触发**绑定的一个或多个事件处理函数。

| 方法                                           | 版本                | 描述                                                         |
| :--------------------------------------------- | :------------------ | :----------------------------------------------------------- |
| ==文档加载事件——与文档资源加载相关的事件==     |                     |                                                              |
| [load()](https://codeplayer.vip/p/j7srd)       | 1.0~~~1.8~~         | 为load事件绑定处理函数。该事件会在资源加载完成时触发。       |
| [ready()](https://codeplayer.vip/p/j7sq0)      | 1.0                 | 为ready事件绑定处理函数。该事件会在DOM载入并准备就绪时触发。 |
| [error()](https://codeplayer.vip/p/j7srf)      | 1.0~~~1.8~~         | 为error事件绑定处理函数。该事件会在资源加载失败时触发。      |
| [unload()](https://codeplayer.vip/p/j7sre)     | 1.0~~~1.8~~         | 为unload事件绑定处理函数。该事件会在用户离开当前页面时触发。 |
| ==浏览器事件——主要用于浏览器Window对象的事件== |                     |                                                              |
| [resize()](https://codeplayer.vip/p/j7srb)     | 1.0                 | 为resize事件绑定处理函数，或触发该事件。该事件会在浏览器窗口大小被改变时触发。 |
| [scroll()](https://codeplayer.vip/p/j7src)     | 1.2                 | 为scroll事件绑定处理函数，或触发该事件。该事件会在元素滚动(滚动条有变化)时触发。 |
| ==表单事件——主要用于表单元素的事件==           |                     |                                                              |
| [focus()](https://codeplayer.vip/p/j7sr4)      | 1.0                 | 为focus事件绑定处理函数，或触发该事件。该事件会在元素获得焦点时触发。 |
| [blur()](https://codeplayer.vip/p/j7sr5)       | 1.0                 | 为blur事件绑定处理函数，或触发该事件。该事件会在元素失去焦点时触发。 |
| [focusin()](https://codeplayer.vip/p/j7sr6)    | 1.0                 | 为focusin事件绑定处理函数。该事件会在元素获得焦点时触发。    |
| [focusout()](https://codeplayer.vip/p/j7sr7)   | 1.0                 | 为focusout事件绑定处理函数。该事件会在元素失去焦点时触发。   |
| [change()](https://codeplayer.vip/p/j7sr9)     | 1.0                 | 为change事件绑定处理函数，或触发该事件。该事件会在元素的值被更改时触发。 |
| [select()](https://codeplayer.vip/p/j7sr8)     | 1.0                 | 为select事件绑定处理函数，或触发该事件。该事件会在元素的用户输入被选中时触发。 |
| [submit()](https://codeplayer.vip/p/j7sra)     | 1.0                 | 为submit事件绑定处理函数，或触发该事件。该事件会在表单被提交时触发。 |
| ==键盘事件——与键盘按键操作相关的事件==         |                     |                                                              |
| [keydown()](https://codeplayer.vip/p/j7srh)    | 1.0                 | 为keydown事件绑定处理函数，或触发该事件。该事件会在键盘按键被按下时触发。 |
| [keypress()](https://codeplayer.vip/p/j7srg)   | 1.0                 | 为keypress事件绑定处理函数，或触发该事件。该事件会在键盘按键被按下时触发。 |
| [keyup()](https://codeplayer.vip/p/j7sri)      | 1.0                 | 为keyup事件绑定处理函数，或触发该事件。该事件会在键盘按键被按下并释放时触发。 |
| ==鼠标事件——与鼠标按键操作相关的事件==         |                     |                                                              |
| [click()](https://codeplayer.vip/p/j7sr1)      | 1.0                 | 为click事件绑定处理函数，或触发该事件。该事件会在点击鼠标按钮时触发。 |
| [dblclick()](https://codeplayer.vip/p/j7sr2)   | 1.0                 | 为dblclick事件绑定处理函数，或触发该事件。该事件会在双击鼠标按钮时触发。 |
| [toggle()](https://codeplayer.vip/p/j7srs)     | 1.0~~~1.8~~~~~1.9~~ | 为click事件绑定两个以上的处理函数，每次触发事件时将轮流切换执行其中的单个函数。 |
| [hover()](https://codeplayer.vip/p/j7sr3)      | 1.0                 | 为hover事件绑定处理函数。该事件会在鼠标进入或离开元素时触发。 |
| [mouseenter()](https://codeplayer.vip/p/j7srj) | 1.0                 | 为mouseenter事件绑定处理函数。该事件会在鼠标进入元素时触发。 |
| [mouseleave()](https://codeplayer.vip/p/j7srl) | 1.0                 | 为mouseleave事件绑定处理函数。该事件会在鼠标离开元素时触发。 |
| [mouseover()](https://codeplayer.vip/p/j7srk)  | 1.0                 | 为mouseover事件绑定处理函数。该事件会在鼠标进入元素时触发。  |
| [mouseout()](https://codeplayer.vip/p/j7srm)   | 1.0                 | 为mouseout事件绑定处理函数。该事件会在鼠标离开元素时触发。   |
| [mousedown()](https://codeplayer.vip/p/j7srn)  | 1.0                 | 为mousedown事件绑定处理函数。该事件会在鼠标按钮被按下时触发。 |
| [mouseup()](https://codeplayer.vip/p/j7sro)    | 1.0                 | 为mouseup事件绑定处理函数。该事件会在鼠标按钮被按下并释放时触发。 |

## 1、jQuery.bind() 函数

`bind()`函数用于**==为每个匹配元素的一个或多个事件绑定事件处理函数==**。

此外，你还可以额外传递给事件处理函数一些所需的数据。

==执行`bind()`时，事件处理函数会绑定到每个匹配元素上。因此你使用`bind()`所有button元素绑定了click事件，是为当时文档中存在的每个button元素绑定click事件。如果之后你向文档中添加了新的button元素，绑定事件不会对其生效。如果你希望绑定事件对未来新添加的元素也生效，请使用[on()](https://codeplayer.vip/p/j7sq1)、[delegate()](https://codeplayer.vip/p/j7sqn)、[live()](https://codeplayer.vip/p/j7sqq)等事件函数(尽量优先使用靠前的事件函数)。==

此外，你可以为同一元素、同一事件类型绑定多个事件处理函数。触发事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`bind()`绑定的事件，请使用unbind()函数。

该函数属于`jQuery`对象(实例)。

语法

`bind()`函数主要有以下两种形式的用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.bind( events [, data ], handler )
```

**用法二**：jQuery 1.4.3 新增支持该用法。

*JavaScript:*

```js
jQueryObject.bind( events [, data ] [, isDefaultBubble ] )
```

**用法三**：jQuery 1.4 新增支持该用法。

*JavaScript:*

```js
jQueryObject.bind( eventsMap )
```

参数

| 参数            | 描述                                                         |
| :-------------- | :----------------------------------------------------------- |
| events          | String类型一个或多个用空格分隔的事件类型和[可选的命名空间](https://codeplayer.vip/p/j7sq5)，例如"click"、"focus click"、"keydown.myPlugin"。 |
| data            | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler         | Function类型指定的事件处理函数。                             |
| isDefaultBubble | 可选/Boolean类型指定触发事件时，是否允许元素的默认行为和事件冒泡。默认为`true`。 |
| eventsMap       | Object类型一个Object对象，其每个属性对应事件类型和可选的命名空间(参数`events`)，属性值对应绑定的事件处理函数(参数`handler`)。 |

关于参数`events`中可选的命名空间(1.4.3+才支持)，请参考最下面的示例代码。

参数`handler`中的`this`指向当前DOM元素。`bind()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

参数`handler`的返回值与DOM原生事件的处理函数返回值作用一致。例如submit(表单提交)事件的事件处理函数返回`false`，可以阻止表单的提交。

参数`isDefaultBubble`用于指示是否允许元素的默认行为和事件冒泡。如果该值为`false`，它将阻止元素的默认行为(例如：触发click事件的链接的默认跳转行为，触发submit事件的表单的默认提交行为)和事件的冒泡传递。

返回值

`bind()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

以点击事件("click")为例，以下是jQuery中事件函数的常规用法(某些函数也存在其它形式的用法，此处暂不列出)：

*JavaScript:*

```js
// 这里的选择器selector用于指定可以触发事件的元素
// 这里的选择器ancestor应是selector的祖辈元素，selector触发的事件可以被其祖辈元素在事件流中捕获，从而以"委托代理"的形式触发事件。

// jQuery 1.0+ (1.4.3+支持参数data)
$("selector").click( [ data ,] handler );

// jQuery 1.0+ (1.4.3+支持参数data)
$("selector").bind( "click" [, data ], handler );

// jQuery 1.3+ (1.4+支持参数data)
$("selector").live( "click" [, data ], handler );

// jQuery 1.4.2+
$("ancestor").delegate( "selector", "click" [, data ], handler );

// jQuery 1.7+
$("ancestor").on( "click", "selector" [, data ], handler );
```

请参考下面这段初始HTML代码：

*HTML:*

```html
<div id="n1">
	<p id="n2"><span>CodePlayer</span></p>
	<p id="n3"><span>专注于编程开发技术分享</span></p>
	<em id="n4">https://codeplayer.vip</em>
</div>
<p id="n5">Google</p>
```

我们为<div>中的所有<p>元素绑定点击事件：

*JavaScript:*

```js
//为div中的所有p元素的click事件绑定事件处理函数
//只有n2、n3可以触发该事件
$("div p").bind("click", function(){
// 这里的this指向触发点击事件的p元素(Element)
	alert( $(this).text() );
});
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-bind-demo)(以下代码请自行复制到演示页面运行)

此外，我们还可以同时绑定多个事件，并为事件处理函数传递一些附加的数据，我们可以通过jQuery为事件处理函数传入的参数`event`(Event事件对象)来进行处理：

*JavaScript:*

```js
var obj = { id: 5, name: "王五" };

//为n5绑定mouseenter mouseleave两个事件，并为其传入附加数据obj
// 附加数据可以是任意类型
$("#n5").bind("mouseenter mouseleave", obj, function(event){
	var $me = $(this);
	var obj = event.data; // 这就是传入的附加数据
	if( event.type == "mouseenter"){
		$me.html( "你好，" + obj.name + "!");
	}else if(event.type == "mouseleave" ){
		$me.html( "再见，" + obj.name + "!");		
	}			
} );
```

此外，如果符合条件的元素是`bind()`函数执行后新添加的，绑定事件**不会**对其生效。同样以初始HTML代码为例，我们可以编写如下jQuery代码：

*JavaScript:*

```js
//为div中的所有p元素的click事件绑定事件处理函数
//只有n2、n3可以触发该事件
$("div p").bind("click", function(event){
	alert( $(this).text() );
});

// 新添加的n6不会触发上述click事件
$("#n1").append('<p id="n6">上述绑定的click事件不会对该元素也生效!</p>');
```

参数`events`还支持为事件类型附加额外的命名空间。当为同一元素绑定多个相同类型的事件处理函数时。使用命名空间，可以在触发事件、移除事件时限定触发或移除的范围。

*JavaScript:*

```js
function clickHandler(event){
	alert( "触发时的命名空间:[" + event.namespace + "]");
}

var $p = $("p");

// A：为所有p元素绑定click事件，定义在foo和bar两个命名空间下
$p.bind( "click.foo.bar", clickHandler );

// B：为所有p元素绑定click事件，定义在test命名空间下
$p.bind( "click.test", clickHandler );

var $n2 = $("#n2");

// 触发所有click事件
$n2.trigger("click"); // 触发A和B (event.namespace = "")

// 触发定义在foo命名空间下的click事件
$n2.trigger("click.foo"); // 触发A (event.namespace = "foo")
// 触发定义在bar命名空间下的click事件
$n2.trigger("click.bar"); // 触发A (event.namespace = "bar")
// 触发同时定义在foo和bar两个命名空间下的click事件
$n2.trigger("click.foo.bar"); // 触发A (event.namespace = "bar.foo")

// 触发定义在test命名空间下的click事件
$n2.trigger("click.test"); // 触发B (event.namespace = "test")
```

`bind()`函数的参数`eventsMap`是一个对象，可以"属性-值"的方式指定多个"事件类型-处理函数"。对应的示例代码如下：

*JavaScript:*

```js
var eventsMap = {
	"mouseenter": function(event){
		$(this).html( "Hello!");		
	},
	
	"mouseleave": function(event){
		$(this).html( "Bye!");
	}
};

//为n5绑定mouseenter mouseleave两个事件
$("#n5").bind( eventsMap );
```

## 2、jQuery.trigger() 函数

`trigger()`函数用于**==在每个匹配元素上触发指定类型的事件==**。

此外，你还可以在触发事件时为事件处理函数传入额外的参数。

使用该函数可以手动触发执行元素上绑定的事件处理函数，也会触发执行该元素的默认行为。

以表单元素<form>为例，使用`trigger("submit")`可以触发该表单绑定的submit事件，也会执行表单submit事件的默认行为——表单提交操作。

根据网友 @飞扬 的反馈，链接标签<a>的`trigger("click")`是一个特例，不会触发链接click事件的默认行为——跳转到对应链接的操作，点此查看[相关详情](http://learn.jquery.com/events/triggering-event-handlers/)。

从jQuery 1.3开始，`trigger()`函数触发的事件还支持事件冒泡，可以冒泡传递到DOM树上。

该函数属于`jQuery`对象(实例)。

语法

`trigger()`函数主要有以下两种形式的用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.trigger( events [, extraArguments ] )
```

在每个匹配元素上触发指定类型(`events`)的事件，并可为事件处理函数传入额外的参数(`extraArguments`)。

**用法二**：jQuery 1.3 新增支持该用法。

*JavaScript:*

```js
jQueryObject.trigger( eventObject [, extraArguments ] )
```

为指定事件处理函数传入的Event对象(`eventObject`)，用于触发执行对应的事件处理函数，并可为事件处理函数传入额外的参数(`extraArguments`)。

参数

| 参数           | 描述                                                         |
| :------------- | :----------------------------------------------------------- |
| events         | String类型指定的事件类型和[可选的命名空间](https://codeplayer.vip/p/j7sq5)，例如"click"、 "focus"、 "keydown.myPlugin"。 |
| extraArguments | 可选/Object类型为事件处理函数传入的额外参数。如果要传入多个参数，请以数组方式传入。 |
| eventObject    | Object类型一个Event对象，用于触发传入该对象的事件处理函数。  |

`trigger()`函数会为触发执行的事件处理函数传入一个默认参数，也就是表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

参数`extraArguments`用于为事件处理函数传入更多额外的参数。如果`extraArguments`是数组形式，则每个元素都将充当函数的参数。

返回值

`trigger()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="btn1" type="button" value="点击1" />
<input id="btn2" type="button" value="点击2" />
<a id="a1" href="#">CodePlayer</a>
<div id="log"></div>
```

首先，我们为上述button和<a>元素绑定事件，然后使用`trigger()`函数直接触发事件，相应的代码如下：

*JavaScript:*

```js
var $log = $("#log");

function handler( event, arg1, arg2 ){
	var html = '<br>触发元素#' + this.id + '的[' + event.type +']事件，额外的函数参数为:' + arg1 + ', ' + arg2;
	$log.append( html );
}

var $buttons = $(":button");

// 为所有button元素的click事件绑定事件处理函数
$buttons.bind( "click", handler );

// 为所有a元素的click、mouseover、mouseleave事件绑定事件处理函数
$("a").bind( "click mouseover mouseleave", handler );


// 触发所有button的click事件
$buttons.trigger("click"); 
/*(追加文本)
触发元素#btn1的[click]事件，额外的函数参数为:undefined, undefined
触发元素#btn2的[click]事件，额外的函数参数为:undefined, undefined
*/


$("#btn1").trigger("click", "CodePlayer");
/*(追加文本)
触发元素#btn1的[click]事件，额外的函数参数为:CodePlayer, undefined
*/

// arg1 = "张三"， arg2 = 20
$("a").trigger("mouseover", ["张三", 20 ] );
/*(追加文本)
触发元素#a1的[mouseover]事件，额外的函数参数为:张三, 20
*/


$("a").trigger("mouseleave", { name: "张三", age: 18 } );
/*(追加文本)
触发元素#a1的[mouseleave]事件，额外的函数参数为:[object Object], undefined
*/
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-trigger-demo)(以下代码请自行复制到演示页面运行)

`trigger()`函数还可以根据传入事件处理函数的Event对象，来触发对应的事件。

*JavaScript:*

```js
var $btn1 = $("#btn1");

// 为btn1元素的click事件绑定事件处理函数
$btn1.bind( "click", function(event){
	alert("click1");	
});

// 为btn1元素的click事件绑定事件处理函数
// 如果传入了一个有效的额外参数，则再次触发click
$btn1.bind( "click", function(event, arg1){
	alert("click2");
	if(arg1)
		$(this).trigger( event );
});

// $btn1.trigger( "click" ); // 调用一次click1、调用一次click2

$btn1.trigger( "click", true ); // 调用两次click1、调用两次click2
```

此外，`trigger()`函数还可以只触发包含指定定命名空间的事件(1.4.3+才支持命名空间)。

*JavaScript:*

```js
function A( event ){
	alert( 'A' );
}
function B( event ){
	alert( 'B' );
}
function C( event ){
	alert( 'C' );
}

var $btn1 = $("#btn1");

// 为btn1元素的click事件绑定事件处理函数
$btn1.bind( "click.foo.bar", A );
$btn1.bind( "click.test.foo", B );
$btn1.bind( "click.test", C );


// 触发btn1的click事件，不限定命名空间
$btn1.trigger("click"); // 触发A、B、C

// 触发btn1的包含命名空间foo的click事件
$btn1.trigger("click.foo"); // 触发A、B

// 触发btn1的包含命名空间test的click事件
$btn1.trigger("click.test"); // 触发B、C

// 触发btn1的同时包含命名空间foo和test的click事件
$btn1.trigger("click.foo.test"); // 触发B
```

## 3、jQuery.resize() 函数

`resize()`函数用于**==为每个匹配元素的resize事件绑定处理函数==**。该函数也可用于触发resize事件。此外，你还可以额外传递给事件处理函数一些数据。

==resize事件会在元素的尺寸大小被调整时触发。该事件常用于window对象(浏览器窗口)或框架页面。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发resize事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`resize()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.resize( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定resize事件的处理函数；没有指定任何参数，则表示触发resize事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`resize()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`resize()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的resize事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`resize()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

现在，我们为`window`对象的resize事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
$(window).resize( function(){
	alert("不建议调整窗口大小!");
} );

// 触发window对象的resize事件
// $(window).resize( );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-resize-demo)(以下代码请自行复制到演示页面运行)

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var minSize = { width: 800, height: 600 };

$(window).resize( minSize, function(event){
	var min = event.data;
	var $dom = $(this);
	if( $dom.width() < min.width ){
		$("body").append("<br>窗口宽度不要小于" + min.width );
	}else if( $dom.height() < min.height ){
		$("body").append("<br>窗口高度不要小于" + min.height);
	}
} );
```

## 4、jQuery.scroll() 函数

`scroll()`函数用于**==为每个匹配元素的scroll事件绑定处理函数==**。该函数也可用于触发scroll事件。此外，你还可以额外传递给事件处理函数一些数据。

==scroll事件会在元素的滚动条位置发生改变时触发。该事件一般仅适用于window对象或其他可滚动元素(一般会出现滚动条)。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发scroll事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`scroll()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.scroll( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定scroll事件的处理函数；没有指定任何参数，则表示触发scroll事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`scroll()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`scroll()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的scroll事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`scroll()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<div id="msg" style="height: 3000px;" ></div>
```

现在，我们为`window`对象的scroll事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
$(window).scroll( function(event){
	$("#msg").append( $(this).scrollTop() + '<br>' );
} );

// 触发window对象的scroll事件
// $(window).scroll( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var maxScrollTop = 1000;

// 向下滚动到据顶部超过1000px时，回到顶部
$(window).scroll( maxScrollTop, function(event){
	var $me = $(this);
	if( $me.scrollTop() > event.data ){
		$me.scrollTop( 0 );
	}
} );
```

## 5、jQuery.focus() 函数

`focus()`函数用于**==为每个匹配元素的focus事件绑定处理函数==**。该函数也可用于触发focus事件。

==focus事件就是获得鼠标光标焦点事件。此外，你还可以额外传递给事件处理函数一些数据。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发focus事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`focus()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.focus( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定focus事件的处理函数；如果没有指定任何参数，则表示触发focus事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`focus()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`focus()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的submit事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`focus()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

并不是所有元素都可以获得焦点，可以获得鼠标光标焦点的元素主要是表单输入元素。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="t1" name="name" type="text" /><span class="tips"></span>
<br>
<input id="t2" name="age" type="text" /><span class="tips"></span>
```

现在，我们为所有text元素的focus事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
var $texts = $(":text");

//为所有text元素的focus事件绑定处理函数
$texts.focus( function(event){
	$(this).css("border", "1px solid blue");
} );

// 为所有text元素的focus事件绑定处理函数
$texts.focus( function(event){
	$(this).css("border-radius", "3px");
} );

// 触发所有text元素的focus事件
// $texts.focus( ); // 调用不带任何参数的focus()函数，会触发每个匹配元素的focus事件
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var inputMap = { "name": "姓名", "age": "年龄" };

// 为所有text元素的focus事件绑定处理函数
$(":text").focus( inputMap, function(event){
	var map = event.data;
	$(this).next(".tips").html( '请输入[' + map[this.name] + ']' );
} );
```

## 6、jQuery.blur() 函数

`blur()`函数用于**==为每个匹配元素的blur事件绑定处理函数==**。该函数也可用于触发blur事件。

==blur事件就是获得失去鼠标光标焦点事件。此外，你还可以额外传递给事件处理函数一些数据。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发blur事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`blur()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.blur( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定blur事件的处理函数；如果没有指定任何参数，则表示触发blur事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`blur()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`blur()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的submit事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`blur()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

并不是所有元素都可以失去焦点，可以获得鼠标光标焦点的元素主要是表单输入元素(只有获得焦点后才可能失去焦点)。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="t1" name="name" type="text" /><span class="tips"></span>
<br>
<input id="t2" name="age" type="text" /><span class="tips"></span>
```

现在，我们为所有text元素的blur事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
var $texts = $(":text");

//为所有text元素的blur事件绑定处理函数
$texts.blur( function(event){
	$(this).css("border", "1px solid blue");
} );

// 为所有text元素的blur事件绑定处理函数
$texts.blur( function(event){
	$(this).css("border-radius", "3px");
} );

// 触发所有text元素的blur事件
// $texts.blur( ); // 调用不带任何参数的blur()函数，会触发每个匹配元素的blur事件
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-blur-demo)(以下代码请自行复制到演示页面运行)

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var inputMap = { "name": "姓名", "age": "年龄" };

// 为所有text元素的blur事件绑定处理函数
// 文本框失去焦点时，进行表单验证，并显示相应的提示信息
$(":text").blur( inputMap, function(event){
	var map = event.data;
	var $me = $(this);
	var tips = '';
	if( !$me.val() ){
		tips = '<span style="color:red;">[' + map[this.name] + ']不能为空!</span>';
	}
	$(this).next(".tips").html( tips );
} );
```

## 7、jQuery.change()函数

`change()`函数用于**==为每个匹配元素的change事件绑定处理函数==**。该函数也可用于触发change事件。此外，你还可以额外传递给事件处理函数一些数据。

==change事件会在文本内容或选项被更改时触发。该事件仅适用于`<input type="text">`和`<textarea>`以及`<select>`。对于text和textarea元素，该事件会在元素失去焦点时发生(文本内容也发生了更改)。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发change事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`change()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.change( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定change事件的处理函数；没有指定任何参数，则表示触发change事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`change()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`change()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的submit事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`change()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="name" name="name" type="text" value="CodePlayer" />
<input id="age" name="age" type="text" value="20" />
<select id="gender" name="gender">
	<option value="男">男性</option>
	<option value="女">女性</option>
</select>
<div id="msg">姓名：[<label for="name">CodePlayer</label>]，年龄：[<label for="age">20</label>]岁，性别：[<label for="gender">男</label>]</div>
```

现在，我们为所有元素的change事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
function handler(event){
	$("label[for='" + this.name + "']").html( this.value );	
}

$(":text").change( handler );
$("#gender").change( handler );

// 触发所有text元素的change事件
// $(":text").change( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var map = { name: "姓名", age: "年龄", gender: "性别" };

function logHandler(event){
	var map = event.data;
	$("#msg").append( new Date().toLocaleString() + ' [' + map[this.name] + ']发生了更改<br>' );	
}

// 记录所有输入每次更改的时间
$(":text").change( map, logHandler );
$("#gender").change( map, logHandler );
```

## 8、jQuery.select() 函数

`select()`函数用于**==为每个匹配元素的select事件绑定处理函数==**。该函数也可用于触发select事件。此外，你还可以额外传递给事件处理函数一些数据。

==select事件会在文本框中的文本内容被选中时触发。该事件仅适用于`<input type="text">`和`<textarea>`文本框。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发select事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`select()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.select( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定select事件的处理函数；没有指定任何参数，则表示触发select事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`select()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`select()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的submit事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`select()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="t1" name="name" type="text" />
<input id="t2" name="age" type="text" />
<div id="msg"></div>
```

现在，我们为所有text元素的select事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
var $texts = $(":text");

//为所有text元素的select事件绑定处理函数
$texts.select( function(event){
	$(this).css("border", "1px solid blue");
} );

// 为所有text元素的select事件绑定处理函数
$texts.select( function(event){
	$(this).css("border-radius", "3px");
} );

// 触发所有text元素的select事件
// $texts.select( ); // 调用不带任何参数的select()函数，会触发每个匹配元素的select事件
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var user = { name: 'CodePlayer', age: 18 };

// 为所有text元素的select事件绑定处理函数
$(":text").select( user, function(event){
	$("#msg").html( event.data.name + "，你选择了[" + this.name + "]中的一些文本内容!" ).show().fadeOut( 2000 );
} );
```

## 9、jQuery.submit() 函数

`submit()`函数用于**==为每个匹配元素的submit事件绑定处理函数==**。该函数也可用于触发submit事件。此外，你还可以额外传递给事件处理函数一些数据。

==submit事件会在表单被提交时触发。该事件仅适用于`<form>`元素。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发submit事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`submit()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.submit( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定submit事件的处理函数；没有指定任何参数，则表示触发submit事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`submit()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`submit()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的submit事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`submit()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<form id="myForm" action="https://codeplayer.vip" method="post">
	<input id="name" name="name" type="text" value="CodePlayer" /><br>
	<input id="age" name="age" type="text" value="20" /><br>
	<input type="submit" value="提交" />
</form>
<div id="msg"></div>
```

现在，我们为<form>元素的submit事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
$("form").submit( function(event){
	if( !$("#name").val() ){
		alert("姓名不能为空!");
		return false; // 返回值为false，将阻止表单提交
	}else if( !$("#age").val() ){
		alert("年龄不能为空!");
		return false; // 返回值为false，将阻止表单提交
	}
} );


// 触发form元素的submit事件
// $("form").submit( );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-submit-demo)(以下代码请自行复制到演示页面运行)

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var map = { name: "姓名", age: "年龄" };

$("form").submit( map, function(event){
	var labelMap = event.data;
	var label = '';

	// 循环验证所有text元素是否为空
	$(this).find(":text").each(function(){
		if( !this.value ){
			label = labelMap[this.name];
			return false;
		}		
	});
	
	if( label ){
		alert( label + "不能为空!" );
		return false;
	}
} );
```

## 10、jQuery.keydown() 函数

`keydown()`函数用于**==为每个匹配元素的keydown事件绑定处理函数==**。此外，你还可以额外传递给事件处理函数一些数据。

==keydown事件会在按下键盘按键时触发。它与keypress事件类似，但keypress着重的是按下该键输入了哪个字符(只有能够打印字符的键才会触发keypress)，keydown着重的是按下了哪个键(按下任何键都可触发keydown)。对于诸如Ctrl、Alt、Shift、Delete、Esc等修饰性和非打印键，请监听keydown事件。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发keydown事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`keydown()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.keydown( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定keydown事件的处理函数；如果没有指定任何参数，则表示触发keydown事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`keydown()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`keydown()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`keydown()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<input id="keys" type="text" />
```

现在，我们为`window`对象的keydown事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

keydown事件的[event.which](https://codeplayer.vip/p/j7sqd)属性返回的是所按下的键盘按键的映射代码值。keypress事件的event.which属性返回的是按键所输入的字符的Unicode值。

*JavaScript:*

```js
$(window).keydown( function(event){
	$("body").append( "<br>你按下的按键的代码值为:[" + event.which + ']' ) ;
} );

// 触发keydown事件
// $(window).keydown( );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-keydown-demo)(以下代码请自行复制到演示页面运行)

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var validKeys = { start: 65, end: 90  };

// 只允许按下的字母键生效 (使用某些输入法可能会绕过该限制)
$("#keys").keydown( validKeys, function(event){
	var keys = event.data;
	return event.which >= keys.start && event.which <= keys.end;
} );
```

## 11、jQuery.keypress() 函数

`keypress()`函数用于**==为每个匹配元素的keypress事件绑定处理函数==**。此外，你还可以额外传递给事件处理函数一些数据。

==keypress事件会在按下键盘按键时触发。它与keydown事件类似，但keypress着重的是按下该键输入了哪个字符(只有能够打印字符的键才会触发keypress)，keydown着重的是按下了哪个键(按下任何键都可触发keydown)。对于诸如Ctrl、Alt、Shift、Delete、Esc等修饰性和非打印键，请监听keydown事件。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发keypress事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`keypress()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.keypress( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定keypress事件的处理函数；如果没有指定任何参数，则表示触发keypress事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`keypress()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`keypress()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`keypress()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<input id="chars" type="text" />
```

现在，我们为`window`对象的keypress事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

keypress事件的[event.which](https://codeplayer.vip/p/j7sqd)属性返回的是按键所输入的字符的Unicode值。keydown事件的event.which属性返回的是所按下的键盘按键的映射代码值。

*JavaScript:*

```js
// 检测按键输入的字符
// Ctrl、Alt等非打印键不会触发keypress事件
$(window).keypress( function(event){
	$("body").append( "<br>你输入了字符[" + String.fromCharCode( event.which ) + "](event.which=" + event.which + ')' ) ;
} );

// 触发keypress事件
// $(window).keypress( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
// { A:65, Z:90, a:97, z:122 }
var validChars = { "A": "A".charCodeAt(0), "Z": "Z".charCodeAt(0), "a": "a".charCodeAt(0), "z": "z".charCodeAt(0)  };

// 只允许输入大小写字母，不允许输入其他字符(使用某些输入法可能会绕过该限制，从而输入中文或其它字符)
$("#chars").keypress( validChars, function(event){
	var ch = event.data;
	return event.which >= ch.A && event.which <= ch.Z || event.which >= ch.a && event.which <= ch.z;
} );
```

## 12、jQuery.keyup() 函数

`keyup()`函数用于**==为每个匹配元素的keyup事件绑定处理函数==**。此外，你还可以额外传递给事件处理函数一些数据。

==keyup事件会在按下键盘按键并释放时触发。例如：你一直按住A键，直到10秒钟后才释放，只会在释放按键的时候触发一次keyup事件。但在这个过程中会触发许多次keydown事件(或keypress事件)。因此，keyup事件无法阻止字符的输入。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发keyup事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`keyup()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.keyup( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定keyup事件的处理函数；如果没有指定任何参数，则表示触发keyup事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`keyup()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`keyup()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`keyup()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<input id="keys" type="text" />
<div id="counter">你按了0个键!</div>
```

现在，我们为`window`对象的keyup事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：



keyup和keydown事件的[event.which](https://codeplayer.vip/p/j7sqd)属性返回的是所按下的键盘按键的映射代码值。keypress事件的event.which属性返回的是按键所输入的字符的Unicode值。

*JavaScript:*

```js
$(window).keyup( function(event){
	$("body").append( "<br>你按下并释放的按键的代码值为:[" + event.which + ']' ) ;
} );


// 触发keyup事件
// $(window).keyup( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var template = "你按了count个按键!";

// 只允许按下的字母键生效 (使用某些输入法可能会绕过该限制)
$("#keys").keyup( template, function(event){
	var $me = $(this);
	var count = $me.data("count") || 0;
	$me.data("count", ++count);
	$("#counter").html( event.data.replace("count", count) );
} );
```

## 13、jQuery.click() 函数

`click()`函数用于**==为每个匹配元素的click事件绑定处理函数==**。该函数也可用于触发click事件。

==click事件就是鼠标按钮单击事件。此外，你还可以额外传递给事件处理函数一些数据。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发click事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`click()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.click( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定click事件的处理函数；没有指定任何参数，则表示触发click事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`click()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`click()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。

返回值

`click()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="btn1" type="button" value="点击1" />
<input id="btn2" type="button" value="点击2" />
<a id="a1" href="https://codeplayer.vip">CodePlayer</a>
```

现在，我们为所有button元素的click事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
// 为所有button元素的click事件绑定处理函数
$(":button").click( function(event){
	alert( this.value + "-1" );
} );

// 为所有button元素的click事件绑定处理函数
$(":button").click( function(event){
	alert( this.value + "-2" );
} );

// 触发所有button元素的click事件
$(":button").click( ); // 调用不带任何参数的click()函数，会触发每个匹配元素的click事件
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-click-demo)(以下代码请自行复制到演示页面运行)

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var user = { name: 'CodePlayer', age: 18 };
// 为所有button元素的click事件绑定处理函数
$(":button").click( user, function(event){
	alert( event.data.name ); // CodePlayer
} );
```

如果通过`click()`函数绑定的事件处理函数的返回值为`false`，则可以阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。

*JavaScript:*

```js
// 点击链接时，阻止链接跳转
$("a").click( function(){
	return false;
} );
```

## 14、jQuery.dblclick() 函数

`dblclick()`函数用于**==为每个匹配元素的dblclick事件绑定处理函数==**。该函数也可用于触发dblclick事件。

==dblclick事件就是鼠标左键双击事件。此外，你还可以额外传递给事件处理函数一些数据。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发dblclick事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`dblclick()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.dblclick( [ [ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定dblclick事件的处理函数；没有指定任何参数，则表示触发dblclick事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`dblclick()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`dblclick()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果函数`handler`的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。<form>表单的submit事件的处理函数返回`false`，可以阻止表单默认的表单提交行为。

返回值

`dblclick()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="btn1" type="button" value="双击1" />
<input id="btn2" type="button" value="双击2" />
```

现在，我们为所有button元素的dblclick事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
// 为所有button元素的dblclick事件绑定处理函数
$(":button").dblclick( function(event){
	alert( this.value + "-1" );
} );

// 为所有button元素的dblclick事件绑定处理函数
$(":button").dblclick( function(event){
	alert( this.value + "-2" );
} );

// 触发所有button元素的dblclick事件
$(":button").dblclick( ); // 调用不带任何参数的dblclick()函数，会触发每个匹配元素的dblclick事件
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var user = { name: 'CodePlayer', age: 18 };
// 为所有button元素的dblclick事件绑定处理函数
$(":button").dblclick( user, function(event){
	alert( event.data.name ); // CodePlayer
} );
```

## 15、jQuery.toggle() 函数

`toggle()`函数用于**==为每个匹配元素的click事件绑定轮流的处理函数==**。

==`toggle()`是一个特殊的事件函数，用于为匹配元素的click事件绑定多个事件处理函数。每次触发click事件时，`toggle()`函数会轮流执行其中的一个事件处理函数。==

例如，我们使用`toggle("click", A, B, C)`为元素的click事件绑定了3个事件处理函数A、B、C。第一次点击执行A，第二次点击执行B，第三次点击执行C，第四次点击又执行A，第五次点击又执行B ……(如果调用了多次`toggle()`，它们之间是独立的)。

要删除通过`toggle()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。例如:`unbind("click")`。

这里介绍的`toggle()`是一个特殊的click事件函数，jQuery还有一个同名的[toggle()函数](https://codeplayer.vip/p/j7srr)，用于切换元素的显示/隐藏。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.0 新增该函数，但从~~1.8~~开始被标记为已过时，并从~~1.9~~开始被移除。

*JavaScript:*

```js
jQueryObject.toggle( handler1, handler2 [, handlerN... ] )
```

参数

| 参数     | 描述                                                   |
| :------- | :----------------------------------------------------- |
| handler1 | Function类型指定的事件处理函数1。                      |
| handler2 | Function类型指定的事件处理函数2。                      |
| handlerN | 可选/Function类型指定的事件处理函数N，可以有任意多个。 |

事件函数`toggle()`会为事件处理函数传入一个参数，即表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

如果事件处理函数的返回值为`false`，则表示阻止元素的默认事件行为，并停止事件在DOM树中冒泡。例如，<a>链接的click事件的处理函数返回`false`，可以阻止链接的默认URL跳转行为。

返回值

`toggle()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<input id="btn" type="button" value="点击" >
```

以下是与`toggle()`事件函数相关的jQuery示例代码，以演示`toggle()`事件函数的具体用法：

*JavaScript:*

```js
function clickHandler1(){
	alert("click-1");
}

function clickHandler2(){
	alert("click-2");
}

function clickHandler3(){
	alert("click-3");
}

function clickHandler4(){
	alert("click-4");
}

$("#btn").toggle( clickHandler1, clickHandler2, clickHandler3, clickHandler4 );

//第1次点击执行clickHandler1
//第2次点击执行clickHandler2
//第3次点击执行clickHandler3
//第4次点击执行clickHandler4

//第5次点击执行clickHandler1
//第6次点击执行clickHandler2
//第7次点击执行clickHandler3
//第8次点击执行clickHandler4

//循环切换执行...
```

## 16、jQuery.hover() 函数

`hover()`函数用于**==为每个匹配元素的hover事件绑定处理函数==**。

==hover事件就是鼠标悬停事件。此外，你还可以额外传递给事件处理函数一些数据。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发hover事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`hover()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

`hover()`函数主要有以下两种用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.hover( handlerIn , handlerOut )
```

分别指定鼠标移入、移出元素时的事件处理函数。

**用法二**：jQuery 1.4 新增支持该用法。

*JavaScript:*

```js
jQueryObject.hover( handlerInAndOut )
```

用法一的变体。当鼠标移入、移出元素时的事件处理函数相同时，只需直接传入一个处理函数作为参数即可。

参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数            | 描述                                                 |
| :-------------- | :--------------------------------------------------- |
| handlerIn       | Function类型鼠标移入元素时需要执行的处理函数。       |
| handlerOut      | Function类型鼠标移出元素时需要执行的处理函数。       |
| handlerInAndOut | Function类型鼠标移入、移出元素时需要执行的处理函数。 |

`hover()`函数的所有参数都是函数，函数内的`this`指向当前DOM元素。`hover()`还会为其传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`hover()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

`hover()`函数与[on()](https://codeplayer.vip/p/j7sq1)函数具有以下等价代码：

*JavaScript:*

```js
$( selector ).hover( handlerInOut );
// 等价于
$( selector ).on( "mouseenter mouseleave", handlerInOut );
```

请参考下面这段初始HTML代码：

*HTML:*

```html
<a id="a1" href="https://codeplayer.vip">CodePlayer</a>
<a id="a2" href="/doc">中文手册</a>
```

现在，我们为所有a元素的hover事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
// 为所有button元素的hover事件绑定处理函数
// 鼠标移入链接时，显示红色；移出链接时，显示蓝色
$("a").hover( function(event){
	$(this).css("color", "red");	
}, function(event){
	$(this).css("color", "blue");
} );

// 为所有button元素的hover事件绑定处理函数
// 鼠标移入、移出链接时，都去掉下划线
$("a").hover( function(event){
	$(this).css("textDecoration", "none");	
} );
```

## 17、jQuery.mouseenter() 函数

`mouseenter()`函数用于**==为每个匹配元素的mouseenter事件绑定处理函数==**。该函数还可用于触发mouseenter事件。此外，你还可以额外传递给事件处理函数一些数据。

==mouseenter事件会在鼠标进入某个元素时触发。它与mouseover事件相似，但mouseenter事件只会在鼠标进入当前元素时触发，而mouseover事件会在鼠标进入当前元素及其任何后代元素时触发(换句话说，mouseover事件支持冒泡)。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发mouseenter事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`mouseenter()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.mouseenter( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定mouseenter事件的处理函数；如果没有指定任何参数，则表示触发mouseenter事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`mouseenter()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`mouseenter()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`mouseenter()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<div>
	<p id="p1">CodePlayer</p>
	<p id="p2">专注于编程技术开发分享</p>
	<p id="p3">https://codeplayer.vip</p>
</div>
<span id="msg"></span>
```

现在，我们为<div>元素的mouseenter事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

mouseenter只会在鼠标进入<div>元素时才会触发，而mouseover会在鼠标进入<div>元素或任何<p>元素时触发。例如：鼠标从p1进入p2会触发<div>元素的mouseover事件，但不会触发<div>元素的mouseenter的事件。

*JavaScript:*

```js
var count = 0;

// 记录触发div元素的mouseenter事件的次数
$("div").mouseenter(function(){
	$("#msg").html( "触发mouseenter的次数：" + ( ++count ) );
});

// 鼠标移入div元素就改变背景颜色
$("div").mouseenter(function(){
	$(this).css( "background", "#eee" );
});


// 触发mouseenter事件
// $("div").mouseenter( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var cssStyle = { background: "#eee", color: "blue" };

//鼠标移入div元素就设置指定的css样式
$("div").mouseenter( cssStyle, function(event){
	var style = event.data;
	$(this).css( style );
} );
```

## 18、jQuery.mouseleave() 函数

`mouseleave()`函数用于**==为每个匹配元素的mouseleave事件绑定处理函数==**。该函数还可用于触发mouseleave事件。此外，你还可以额外传递给事件处理函数一些数据。

==mouseleave事件会在鼠标离开某个元素时触发。它与mouseout事件相似，但mouseleave事件只会在鼠标离开当前元素时触发，而mouseout事件会在鼠标离开当前元素及其任何后代元素时触发(换句话说，mouseout事件支持冒泡)。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发mouseleave事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`mouseleave()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.mouseleave( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定mouseleave事件的处理函数；如果没有指定任何参数，则表示触发mouseleave事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`mouseleave()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`mouseleave()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`mouseleave()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<div>
	<p id="p1">CodePlayer</p>
	<p id="p2">专注于编程技术开发分享</p>
	<p id="p3">https://codeplayer.vip</p>
</div>
<span id="msg"></span>
```

现在，我们为<div>元素的mouseleave事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：



mouseleave只会在鼠标离开<div>元素时才会触发，而mouseout会在鼠标离开<div>元素或任何<p>元素时触发。例如：鼠标从p1进入p2(即离开p1)会触发<div>元素的mouseout事件，但不会触发<div>元素的mouseleave的事件。

*JavaScript:*

```js
var count = 0;

//记录触发div元素的mouseleave事件的次数
$("div").mouseleave(function(){
	$("#msg").html( "触发mouseleave的次数：" + ( ++count ) );
});

//鼠标离开div元素就改变背景颜色
$("div").mouseleave(function(){
	$(this).css( "color", "purple" );
});


// 触发mouseleave事件
// $("div").mouseleave( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var cssStyle = { background: "#eee", color: "blue" };

//鼠标离开div元素就设置指定的css样式
$("div").mouseleave( cssStyle, function(event){
	var style = event.data;
	$(this).css( style );
} );
```

## 19、jQuery.mouseover() 函数

`mouseover()`函数用于**==为每个匹配元素的mouseover事件绑定处理函数==**。该函数还可用于触发mouseover事件。此外，你还可以额外传递给事件处理函数一些数据。

==mouseover事件会在鼠标进入某个元素时触发。它与mouseenter事件相似，但mouseenter事件只会在鼠标进入当前元素时触发，而mouseover事件会在鼠标进入当前元素及其任何后代元素时触发(换句话说，mouseover事件支持冒泡)。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发mouseenter事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`mouseover()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.mouseover( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定mouseover事件的处理函数；如果没有指定任何参数，则表示触发mouseover事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`mouseover()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`mouseover()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`mouseover()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<div>
	<p id="p1">CodePlayer</p>
	<p id="p2">专注于编程技术开发分享</p>
	<p id="p3">https://codeplayer.vip</p>
</div>
<span id="msg"></span>
```

现在，我们为<div>元素的mouseover事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

mouseover只会在鼠标进入<div>元素时才会触发，而mouseover会在鼠标进入<div>元素或任何<p>元素时触发。例如：从p1进入p2也会触发<div>元素的mouseover事件，但不会触发<div>元素的mouseenter的事件。

*JavaScript:*

```js
var count = 0;

// 记录触发div元素的mouseover事件的次数
$("div").mouseover(function(){
	$("#msg").html( "触发mouseover的次数：" + ( ++count ) );
});

// 鼠标移入div元素就改变背景颜色
$("div").mouseover(function(){
	$(this).css( "background", "#eee" );
});


// 触发mouseover事件
// $("div").mouseover( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var cssStyle = { background: "#eee", color: "blue" };

//鼠标移入div元素就设置指定的css样式
$("div").mouseover( cssStyle, function(event){
	var style = event.data;
	$(this).css( style );
} );
```

## 20、jQuery.mouseout() 函数

`mouseout()`函数用于**==为每个匹配元素的mouseout事件绑定处理函数==**。该函数还可用于触发mouseout事件。此外，你还可以额外传递给事件处理函数一些数据。

==mouseout事件会在鼠标离开某个元素时触发。它与mouseleave事件相似，但mouseleave事件只会在鼠标离开当前元素时触发，而mouseout事件会在鼠标离开当前元素及其任何后代元素时触发(换句话说，mouseout事件支持冒泡)。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发mouseout事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`mouseout()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.mouseout( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定mouseout事件的处理函数；如果没有指定任何参数，则表示触发mouseout事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`mouseout()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`mouseout()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`mouseout()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<div>
	<p id="p1">CodePlayer</p>
	<p id="p2">专注于编程技术开发分享</p>
	<p id="p3">https://codeplayer.vip</p>
</div>
<span id="msg"></span>
```

现在，我们为<div>元素的mouseout事件绑定处理函数(可以绑定多个，触发时按照绑定顺序依次执行)：

mouseleave只会在鼠标离开<div>元素时才会触发，而mouseout会在鼠标离开<div>元素或任何<p>元素时触发。例如：鼠标从p1进入p2(即离开p1)会触发<div>元素的mouseout事件，但不会触发<div>元素的mouseleave的事件。

*JavaScript:*

```js
var count = 0;

//记录触发div元素的mouseout事件的次数
$("div").mouseout(function(){
	$("#msg").html( "触发mouseout的次数：" + ( ++count ) );
});

//鼠标离开div元素就改变背景颜色
$("div").mouseout(function(){
	$(this).css( "color", "purple" );
});


// 触发mouseout事件
// $("div").mouseout( );
```

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
var cssStyle = { background: "#eee", color: "blue" };

//鼠标离开div元素就设置指定的css样式
$("div").mouseout( cssStyle, function(event){
	var style = event.data;
	$(this).css( style );
} );
```

## 21、jQuery.mousedown() 函数

`mousedown()`函数用于**==为每个匹配元素的mousedown事件绑定处理函数==**。该函数还可用于触发mousedown事件。此外，你还可以额外传递给事件处理函数一些数据。

==mousedown事件会在鼠标按钮被按下时触发。mouseup事件会在按下鼠标按钮并**释放**时触发。注意：如果一直按住鼠标按钮不放，也只会触发一次mousedown事件。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发mousedown事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`mousedown()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.mousedown( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定mousedown事件的处理函数；如果没有指定任何参数，则表示触发mousedown事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`mousedown()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`mousedown()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`mousedown()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<p>点击此处0次</p>
<p>点击此处0次</p>
<div id="log"></div>
```

现在，我们为<div>元素的mousedown事件绑定处理函数(可以绑定多次，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
// 分别记录每个p元素的mousedown事件的触发次数
$("p").mousedown(function(){
	var $me = $(this);
	var count = $me.data("count") || 0;
	$me.data("count", ++count );
	$me.html( '点击此处' + count + '次' );	
});

//记录触发div元素的mouseleave事件的次数
$("p").mousedown(function(){
	$("#log").html( '你在p元素中最后一次按下鼠标按钮的时间为' + new Date().toLocaleString() );	
});

// 触发mousedown事件
// $("p").mousedown( );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-mousedown-demo)(以下代码请自行复制到演示页面运行)

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
// event.which属性值：1表示鼠标左键，2表示鼠标中键(滚轮键)，3表示鼠标右键。

var buttonMap = { "1": "左", "2": "中", "3": "右" };

//记录触发div元素的mouseleave事件的次数
$(window).mousedown(buttonMap, function(event){
	var map = event.data;
	$("#log").prepend( '你按下了鼠标[' + map[event.which] + ']键<br>');	
});
```

## 22、jQuery.mouseup() 函数

`mouseup()`函数用于**==为每个匹配元素的mouseup事件绑定处理函数==**。该函数还可用于触发mouseup事件。此外，你还可以额外传递给事件处理函数一些数据。

==mouseup事件会在鼠标按钮被释放时触发。mousedown事件会在鼠标按钮被按下(无需释放)时触发。==

此外，你可以为同一元素多次调用该函数，从而绑定多个事件处理函数。触发mouseup事件时，jQuery会按照绑定的先后顺序依次执行绑定的事件处理函数。

要删除通过`mouseup()`绑定的事件，请使用[unbind()](https://codeplayer.vip/p/j7sqt)函数。

该函数属于`jQuery`对象(实例)。

语法

*JavaScript:*

```js
jQueryObject.mouseup( [[ data ,]  handler ] )
```

如果指定了至少一个参数，则表示绑定mouseup事件的处理函数；如果没有指定任何参数，则表示触发mouseup事件。

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| data    | 可选/任意类型触发事件时，需要通过[event.data](https://codeplayer.vip/p/j7sq3)传递给事件处理函数的任意数据。 |
| handler | 可选/Function类型指定的事件处理函数。                        |

jQuery 1.4.3 新增支持：`mouseup()`支持`data`参数。

参数`handler`中的`this`指向当前DOM元素。`mouseup()`还会为`handler`传入一个参数：表示当前事件的[Event对象](https://codeplayer.vip/p/j7sql)。

返回值

`mouseup()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考以下HTML示例代码：

*HTML:*

```html
<p>点击此处0次</p>
<p>点击此处0次</p>
<div id="log"></div>
```

现在，我们为<div>元素的mouseup事件绑定处理函数(可以绑定多次，触发时按照绑定顺序依次执行)：

*JavaScript:*

```js
// 分别记录每个p元素的mouseup事件的触发次数
$("p").mouseup(function(){
	var $me = $(this);
	var count = $me.data("count") || 0;
	$me.data("count", ++count );
	$me.html( '点击此处' + count + '次' );	
});

//记录触发div元素的mouseleave事件的次数
$("p").mouseup(function(){
	$("#log").html( '你在p元素中最后一次按下鼠标按钮的时间为' + new Date().toLocaleString() );	
});

// 触发mouseup事件
// $("p").mouseup( );
```

[运行代码](https://codeplayer.vip/diy.php?f=jquery-mouseup-demo)(以下代码请自行复制到演示页面运行)

我们还可以为事件处理函数传递一些附加的数据。此外，通过jQuery为事件处理函数传入的参数[Event对象](https://codeplayer.vip/p/j7sql)，我们可以获取当前事件的相关信息(比如事件类型、触发事件的DOM元素、附加数据等)：

*JavaScript:*

```js
// event.which属性值：1表示鼠标左键，2表示鼠标中键(滚轮键)，3表示鼠标右键。

var buttonMap = { "1": "左", "2": "中", "3": "右" };

//记录触发div元素的mouseleave事件的次数
$(window).mouseup(buttonMap, function(event){
	var map = event.data;
	$("#log").prepend( '你按下并松开了鼠标[' + map[event.which] + ']键<br>');	
});
```

# 八、效果

## 0、动态效果一览表

| ==动画效果API——用于进行文档处理，并可能带有过渡的动画效果。 |       |                                                              |
| ----------------------------------------------------------- | ----- | ------------------------------------------------------------ |
| [show()](https://codeplayer.vip/p/j7srp)                    | 1.0   | 显示匹配的元素，并可选附带过渡动画效果。                     |
| [hide()](https://codeplayer.vip/p/j7srq)                    | 1.0   | 隐藏匹配的元素，并可选附带过渡动画效果。                     |
| [toggle()](https://codeplayer.vip/p/j7srr)                  | 1.0   | 切换显示/隐藏匹配的元素(如果显示就隐藏，如果隐藏就显示)，并可选附带过渡动画效果。 |
| [slideDown()](https://codeplayer.vip/p/j7srt)               | 1.0   | 显示匹配的元素，并带有向下滑动的动画效果。                   |
| [slideUp()](https://codeplayer.vip/p/j7sru)                 | 1.0   | 隐藏匹配的元素，并带有向上滑动的动画效果。                   |
| [slideToggle()](https://codeplayer.vip/p/j7srv)             | 1.0   | 切换显示/隐藏匹配的元素，并带有向下/上滑动的动画效果。       |
| [fadeIn()](https://codeplayer.vip/p/j7ss0)                  | 1.0   | 显示匹配的元素，并带有"淡入"的动画效果。                     |
| [fadeOut()](https://codeplayer.vip/p/j7ss1)                 | 1.0   | 隐藏匹配的元素，并带有"淡出"的动画效果。                     |
| [fadeToggle()](https://codeplayer.vip/p/j7ss2)              | 1.0   | 切换显示/隐藏匹配的元素，并带有"淡入"/"淡出"的动画效果。     |
| [animate()](https://codeplayer.vip/p/j7ss3)                 | 1.0   | 设置元素的CSS样式属性，并带有从当前样式到目标样式过渡的动画效果。 |
| [stop()](https://codeplayer.vip/p/j7ss4)                    | 1.2   | 停止匹配元素上当前正在运行的动画。                           |
| [delay()](https://codeplayer.vip/p/j7ss5)                   | 1.4   | 设置一个定时器，以延迟队列中下一项的执行。                   |
| [finish()](https://codeplayer.vip/p/j7ss6)                  | 1.9   | 立即完成队列中的所有动画(显示所有动画执行完后的目标样式，但省略动画过程)，并清空队列。 |
| [jQuery.fx.off](https://codeplayer.vip/p/j7ss7)             | 1.3   | 全局属性是否全局性地禁用所有动画效果。                       |
| [jQuery.fx.interval](https://codeplayer.vip/p/j7ss8)        | 1.4.3 | 全局属性设置jQuery动画的帧速(每隔多长时间绘制一帧图像)。     |
| [queue()](https://codeplayer.vip/p/j7ssq)                   | 1.2   | 创建或替换一个函数队列，或向其中添加一个队列函数。           |
| [dequeue()](https://codeplayer.vip/p/j7ssr)                 | 1.2   | 移除队列中的第一个函数，并执行该函数。                       |
| [clearQueue()](https://codeplayer.vip/p/j7sss)              | 1.4   | 清空队列中所有尚未执行的队列函数。                           |

## 1、jQuery.show() 函数

`show()`函数用于**==显示所有匹配的元素==**。此外，你==还可以指定元素显示的过渡动画效果==。

==如果元素本身是可见的，则不对其作任何改变。如果元素是隐藏的，则使其可见。==

与该函数相对的是[hide()](https://codeplayer.vip/p/j7srq)函数，用于**隐藏所有匹配的元素**。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.0 新增该函数。`show()`函数主要有以下两种形式的用法：

**用法一**：jQuery 1.4.3 新增支持参数`easing`。

*JavaScript:*

```js
jQueryObject.show( [ duration ] [, easing ] [, complete ] )
```

**用法二**：

*JavaScript:*

```js
jQueryObject.show( options )
```

用法二是用法一的变体。以对象形式指定所需的选项参数(可指定比用法一更多的选项参数)。

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| duration | 可选/String/Number类型指定过渡动画运行多长时间(毫秒数)，默认值为400。该参数也可以为字符串"fast"(=200)或"slow"(=600)。 |
| easing   | 可选/String类型指定使用何种动画效果，默认为"swing"，还可以设为"linear"或其他自定义的动画样式的函数名称。 |
| complete | 可选/Function类型元素显示完毕后需要执行的函数。函数内的`this`指向当前DOM元素。 |
| options  | Object类型指定的选项参数对象。                               |

如果没有为`show()`指定任何参数，则将以最快方式直接显示元素，不使用动画效果。

参数`options`对象可以识别如下的属性(以下属性均是**可选**的)：

| 属性     | 属性描述                                                     |
| :------- | :----------------------------------------------------------- |
| duration | 参见参数`duration`。                                         |
| easing   | 参见参数`easing`。                                           |
| complete | 参见参数`complete`。                                         |
| queue    | Boolean类型指示是否将动画放入效果队列中，默认为`true`。从1.7版本开始，该参数可以为字符串，用于放入指定名称的效果队列。如果你指定的队列不会自动开始，你需要手动调用dequeue("queueName")来启动队列。 |

此外，jQuery 1.4 和 1.8 还为参数`options`新增了许多新的选项支持，但这些参数并不常用，此处不再赘述，详见[jQuery官方文档](http://api.jquery.com/show/#show-options)。

返回值

`show()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>CodePlayer</p>
<p>专注于编程开发技术分享</p>
显示效果：
<select id="animation">
	<option value="1">show( )</option>
	<option value="2">show( "slow" )</option>
	<option value="3">show( 3000 )</option>
	<option value="4">show( 1000, complete )</option>
	<option value="5">show( 1000, "linear" )</option>
	<option value="6">show( options )</option>
</select>
<input id="btnShow" type="button" value="显示" /> <input id="btnHide" type="button" value="隐藏" />
```

以下是与`show()`函数相关的jQuery示例代码，以演示`show()`函数的具体用法：

*JavaScript:*

```js
// 【显示】按钮
$("#btnShow").click( function(){
	var v = $("#animation").val();
	if( v == "1" ){
		$("p").show( );		
	}else if(v == "2"){
		$("p").show( "slow" );	
	}else if(v == "3"){
		$("p").show( 3000 );	
	}else if(v == "4"){
		$("p").show( 1000, function(){
			alert("显示完毕!");
		} );	
	}else if(v == "5"){
		$("p").show( 1000, "linear" );	
	}else if(v == "6"){
		$("p").show( { duration: 1000 } );	
	}
} );

// 【隐藏】按钮
$("#btnHide").click( function(){
	$("p").hide( );
} );
```

## 2、jQuery.hide() 函数

`hide()`函数用于**==隐藏所有匹配的元素==**。此外，你还可以指定元素隐藏的过渡动画效果。

==如果元素本身是不可见的，则不对其作任何改变。如果元素是可见的，则将其隐藏。==

与该函数**相对**的是[show()](https://codeplayer.vip/p/j7srp)函数，用于**显示所有匹配的元素**。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.0 新增该函数。`hide()`函数主要有以下两种形式的用法：

**用法一**：jQuery 1.4.3 新增支持参数`easing`。

*JavaScript:*

```js
jQueryObject.hide( [ duration ] [, easing ] [, complete ] )
```

**用法二**：

*JavaScript:*

```js
jQueryObject.hide( options )
```

用法二是用法一的变体。以对象形式指定所需的选项参数(可指定比用法一更多的选项参数)。

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| duration | 可选/String/Number类型指定过渡动画运行多长时间(毫秒数)，默认值为400。该参数也可以为字符串"fast"(=200)或"slow"(=600)。 |
| easing   | 可选/String类型指定使用何种动画效果，默认为"swing"，还可以设为"linear"或其他自定义的动画样式的函数名称。 |
| complete | 可选/Function类型元素隐藏完毕后需要执行的函数。函数内的`this`指向当前DOM元素。 |
| options  | Object类型指定的选项参数对象。                               |

如果没有为`hide()`指定任何参数，则将以最快方式直接隐藏元素，不使用动画效果。

参数`options`对象可以识别如下的属性(以下属性均是**可选**的)：

| 属性     | 属性描述                                                     |
| :------- | :----------------------------------------------------------- |
| duration | 参见参数`duration`。                                         |
| easing   | 参见参数`easing`。                                           |
| complete | 参见参数`complete`。                                         |
| queue    | Boolean类型指示是否将动画放入效果队列中，默认为`true`。从1.7版本开始，该参数可以为字符串，用于放入指定名称的效果队列。如果你指定的队列不会自动开始，你需要手动调用dequeue("queueName")来启动队列。 |

此外，jQuery 1.4 和 1.8 还为参数`options`新增了许多新的选项支持，但这些参数并不常用，此处不再赘述，详见[jQuery官方文档](http://api.jquery.com/hide/#hide-options)。

返回值

`hide()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>CodePlayer</p>
<p>专注于编程开发技术分享</p>
隐藏效果：
<select id="animation">
	<option value="1">hide( )</option>
	<option value="2">hide( "slow" )</option>
	<option value="3">hide( 3000 )</option>
	<option value="4">hide( 1000, complete )</option>
	<option value="5">hide( 1000, "linear" )</option>
	<option value="6">hide( options )</option>
</select>
<input id="btnShow" type="button" value="显示" />
<input id="btnHide" type="button" value="隐藏" />
```

以下是与`hide()`函数相关的jQuery示例代码，以演示`hide()`函数的具体用法：

*JavaScript:*

```js
// 【显示】按钮
$("#btnShow").click( function(){
	$("p").show( );
} );

//【隐藏】按钮
$("#btnHide").click( function(){
	var v = $("#animation").val();
	if( v == "1" ){
		$("p").hide( );		
	}else if(v == "2"){
		$("p").hide( "slow" );	
	}else if(v == "3"){
		$("p").hide( 3000 );	
	}else if(v == "4"){
		$("p").hide( 1000, function(){
			alert("隐藏完毕!");
		} );
	}else if(v == "5"){
		$("p").hide( 1000, "linear" );	
	}else if(v == "6"){
		$("p").hide( { duration: 1000 } );	
	}
} );
```

## 3、jQuery.toggle() 函数

`toggle()`函数用于**==切换所有匹配的元素==**。此外，你还可以指定元素切换的过渡动画效果。

==所谓"切换"，也就是如果元素当前是可见的，则将其隐藏；如果元素当前是隐藏的，则使其显示(可见)。==

这里介绍的`toggle()`函数用于切换元素的显示/隐藏。jQuery还有一个同名的事件函数[toggle()](https://codeplayer.vip/p/j7srs)，用于绑定click事件并在触发时轮流切换执行不同的事件处理函数。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.0 新增该函数。`toggle()`函数主要有以下两种形式的用法：

**用法一**：jQuery 1.4.3 新增支持参数`easing`。

*JavaScript:*

```js
jQueryObject.toggle( [ duration ] [, easing ] [, complete ] )
```

**用法二**：

*JavaScript:*

```js
jQueryObject.toggle( options )
```

用法二是用法一的变体。以对象形式指定所需的选项参数(可指定比用法一更多的选项参数)。

**用法三**：jQuery 1.3 新增支持该用法。

*JavaScript:*

```js
jQueryObject.toggle( showOrHide )
```

通过布尔值`showOrHide`来指定是显示还是隐藏元素。

参数

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| duration   | 可选/String/Number类型指定过渡动画运行多长时间(毫秒数)，默认值为400。该参数也可以为字符串"fast"(=200)或"slow"(=600)。 |
| easing     | 可选/String类型指定使用何种动画效果，默认为"swing"，还可以设为"linear"或其他自定义的动画样式的函数名称。 |
| complete   | 可选/Function类型元素显示完毕后需要执行的函数。函数内的`this`指向当前DOM元素。 |
| options    | Object类型指定的选项参数对象。                               |
| showOrHide | Boolean类型指定显示/隐藏元素的布尔值。如果为`true`，就显示元素，否则隐藏元素。 |

如果没有为`toggle()`指定任何参数，则将以最快方式直接显示/隐藏元素，不使用动画效果。

参数`options`对象可以识别如下的属性(以下属性均是**可选**的)：

| 属性     | 属性描述                                                     |
| :------- | :----------------------------------------------------------- |
| duration | 参见参数`duration`。                                         |
| easing   | 参见参数`easing`。                                           |
| complete | 参见参数`complete`。                                         |
| queue    | Boolean类型指示是否将动画放入效果队列中，默认为`true`。从1.7版本开始，该参数可以为字符串，用于放入指定名称的效果队列。如果你指定的队列不会自动开始，你需要手动调用dequeue("queueName")来启动队列。 |

此外，jQuery 1.4 和 1.8 还为参数`options`新增了许多新的选项支持，但这些参数并不常用，此处不再赘述，详见[jQuery官方文档](http://api.jquery.com/toggle/#toggle-options)。

返回值

`toggle()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>CodePlayer</p>
<p>专注于编程开发技术分享</p>
切换效果：
<select id="animation">
	<option value="1">toggle( )</option>
	<option value="2">toggle( "slow" )</option>
	<option value="3">toggle( 3000 )</option>
	<option value="4">toggle( 1000, complete )</option>
	<option value="5">toggle( 1000, "linear" )</option>
	<option value="6">toggle( options )</option>
	<option value="7">toggle( true )</option>
	<option value="8">toggle( false )</option>
</select>
<input id="btnSwitch" type="button" value="切换显示/隐藏" >
```

以下是与`toggle()`函数相关的jQuery示例代码，以演示`toggle()`函数的具体用法：

*JavaScript:*

```js
//【切换显示/隐藏】按钮
$("#btnSwitch").click( function(){
	var v = $("#animation").val();
	if( v == "1" ){
		$("p").toggle( );		
	}else if(v == "2"){
		$("p").toggle( "slow" );	
	}else if(v == "3"){
		$("p").toggle( 3000 );	
	}else if(v == "4"){
		$("p").toggle( 1000, function(){
			alert("切换完毕!");
		} );
	}else if(v == "5"){
		$("p").toggle( 1000, "linear" );	
	}else if(v == "6"){
		$("p").toggle( { duration: 1000 } );	
	}else if(v == "7"){
		$("p").toggle( true ); // 相当于$("p").show();	
	}else if(v == "8"){
		$("p").toggle( false );	 // 相当于$("p").hide();
	}
} );
```

## 4、jQuery.slideDown() 函数

`slideDown()`函数用于**==显示所有匹配的元素，并带有向下滑动的过渡动画效果==**。

==向下滑动的动画效果，即元素可见区域的高度从0逐渐增大到其原有高度(向下逐渐展开)。==

==如果元素本身是可见的，则不对其作任何改变。如果元素是隐藏的，则使其可见。==

与该函数相对的是[slideUp()](https://codeplayer.vip/p/j7sru)函数，用于**隐藏所有匹配的元素，并带有向上滑动的过渡动画效果**。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.0 新增该函数。`slideDown()`函数主要有以下两种形式的用法：

**用法一**：jQuery 1.4.3 新增支持参数`easing`。

*JavaScript:*

```js
jQueryObject.slideDown( [ duration ] [, easing ] [, complete ] )
```

**用法二**：

*JavaScript:*

```js
jQueryObject.slideDown( options )
```

用法二是用法一的变体。以对象形式指定所需的选项参数(可指定比用法一更多的选项参数)。

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| duration | 可选/String/Number类型指定过渡动画运行多长时间(毫秒数)，默认值为400。该参数也可以为字符串"fast"(=200)或"slow"(=600)。 |
| easing   | 可选/String类型指定使用何种动画效果，默认为"swing"，还可以设为"linear"或其他自定义的动画样式的函数名称。 |
| complete | 可选/Function类型元素显示完毕后需要执行的函数。函数内的`this`指向当前DOM元素。 |
| options  | Object类型指定的选项参数对象。                               |

参数`options`对象可以识别如下的属性(以下属性均是**可选**的)：

| 属性     | 属性描述                                                     |
| :------- | :----------------------------------------------------------- |
| duration | 参见参数`duration`。                                         |
| easing   | 参见参数`easing`。                                           |
| complete | 参见参数`complete`。                                         |
| queue    | Boolean类型指示是否将动画放入效果队列中，默认为`true`。从1.7版本开始，该参数可以为字符串，用于放入指定名称的效果队列。如果你指定的队列不会自动开始，你需要手动调用dequeue("queueName")来启动队列。 |

此外，jQuery 1.4 和 1.8 还为参数`options`新增了许多新的选项支持，但这些参数并不常用，此处不再赘述，详见[jQuery官方文档](http://api.jquery.com/slideDown/#slideDown-options)。

返回值

`slideDown()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>CodePlayer</p>
<p>专注于编程开发技术分享</p>
向下滑动的显示效果：
<select id="animation">
	<option value="1">slideDown( )</option>
	<option value="2">slideDown( "slow" )</option>
	<option value="3">slideDown( 3000 )</option>
	<option value="4">slideDown( 1000, complete )</option>
	<option value="5">slideDown( 1000, "linear" )</option>
	<option value="6">slideDown( options )</option>
</select>
<input id="btnSlideDown" type="button" value="显示" />
<input id="btnHide" type="button" value="隐藏" />
```

以下是与`slideDown()`函数相关的jQuery示例代码，以演示`slideDown()`函数的具体用法：

*JavaScript:*

```js
// 【显示】按钮
$("#btnSlideDown").click( function(){
	var v = $("#animation").val();
	if( v == "1" ){
		$("p").slideDown( );		
	}else if(v == "2"){
		$("p").slideDown( "slow" );	
	}else if(v == "3"){
		$("p").slideDown( 3000 );	
	}else if(v == "4"){
		$("p").slideDown( 1000, function(){
			alert("显示完毕!");
		} );	
	}else if(v == "5"){
		$("p").slideDown( 1000, "linear" );	
	}else if(v == "6"){
		$("p").slideDown( { duration: 1000 } );	
	}
} );

// 【隐藏】按钮
$("#btnHide").click( function(){
	$("p").hide( );
} );
```

## 5、jQuery.fadeIn() 函数

`fadeIn()`函数用于**==显示所有匹配的元素，并带有淡入的过渡动画效果==**。

==淡入的动画效果，即元素的不透明度的比例从0%逐渐增加到100%。==

==如果元素本身是可见的，则不对其作任何改变。如果元素是隐藏的，则使其可见。==

与该函数相对的是[fadeOut()](https://codeplayer.vip/p/j7ss1)函数，用于**隐藏所有匹配的元素，并带有淡出的过渡动画效果**。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.0 新增该函数。`fadeIn()`函数主要有以下两种形式的用法：

**用法一**：jQuery 1.4.3 新增支持参数`easing`。

*JavaScript:*

```js
jQueryObject.fadeIn( [ duration ] [, easing ] [, complete ] )
```

**用法二**：

*JavaScript:*

```js
jQueryObject.fadeIn( options )
```

用法二是用法一的变体。以对象形式指定所需的选项参数(可指定比用法一更多的选项参数)。

参数

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| duration | 可选/String/Number类型指定过渡动画运行多长时间(毫秒数)，默认值为400。该参数也可以为字符串"fast"(=200)或"slow"(=600)。 |
| easing   | 可选/String类型指定使用何种动画效果，默认为"swing"，还可以设为"linear"或其他自定义的动画样式的函数名称。 |
| complete | 可选/Function类型元素显示完毕后需要执行的函数。函数内的`this`指向当前DOM元素。 |
| options  | Object类型指定的选项参数对象。                               |

参数`options`对象可以识别如下的属性(以下属性均是**可选**的)：

| 属性     | 属性描述                                                     |
| :------- | :----------------------------------------------------------- |
| duration | 参见参数`duration`。                                         |
| easing   | 参见参数`easing`。                                           |
| complete | 参见参数`complete`。                                         |
| queue    | Boolean类型指示是否将动画放入效果队列中，默认为`true`。从1.7版本开始，该参数可以为字符串，用于放入指定名称的效果队列。如果你指定的队列不会自动开始，你需要手动调用dequeue("queueName")来启动队列。 |

此外，jQuery 1.4 和 1.8 还为参数`options`新增了许多新的选项支持，但这些参数并不常用，此处不再赘述，详见[jQuery官方文档](http://api.jquery.com/fadeIn/#fadeIn-options)。

返回值

`fadeIn()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>CodePlayer</p>
<p>专注于编程开发技术分享</p>
淡入的显示效果：
<select id="animation">
	<option value="1">fadeIn( )</option>
	<option value="2">fadeIn( "slow" )</option>
	<option value="3">fadeIn( 3000 )</option>
	<option value="4">fadeIn( 2000, complete )</option>
	<option value="5">fadeIn( 1000, "linear" )</option>
	<option value="6">fadeIn( options )</option>
</select>
<input id="btnFadeIn" type="button" value="显示" > <input id="btnHide" type="button" value="隐藏" >
```

以下是与`fadeIn()`函数相关的jQuery示例代码，以演示`fadeIn()`函数的具体用法：

*JavaScript:*

```js
//【显示】按钮
$("#btnFadeIn").click( function(){
	var v = $("#animation").val();
	if( v == "1" ){
		$("p").fadeIn( );		
	}else if(v == "2"){
		$("p").fadeIn( "slow" );	
	}else if(v == "3"){
		$("p").fadeIn( 3000 );	
	}else if(v == "4"){
		$("p").fadeIn( 2000, function(){
			alert("显示完毕!");
		} );	
	}else if(v == "5"){
		$("p").fadeIn( 1000, "linear" );	
	}else if(v == "6"){
		$("p").fadeIn( { duration: 1000 } );	
	}
} );

// 【隐藏】按钮
$("#btnHide").click( function(){
	$("p").hide( );
} );
```

## 6、jQuery.animate() 函数

`animate()`函数用于**==执行一个基于css属性的自定义动画==**。

==你可以为匹配的元素设置css样式，`animate()`函数将会执行一个从当前样式到指定的css样式的一个过渡动画。==

例如：某个div元素的当前高度为100px，将其CSS height属性设为200px，`animate()`将会执行一个将div元素的高度从100px逐渐增加到200px的过渡动画。

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.0 新增该函数。`animate()`函数主要有以下两种形式的用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.animate( cssProperties [, duration ] [, easing ] [, complete ] )
```

**用法二**：

*JavaScript:*

```js
jQueryObject.animate( cssProperties, options )
```

用法二是用法一的变体。以对象形式指定所需的选项参数(可指定比用法一更多的选项参数)。

参数

| 参数          | 描述                                                         |
| :------------ | :----------------------------------------------------------- |
| cssProperties | Object类型一个或多个css属性的键值对所构成的Object对象。      |
| duration      | 可选/String/Number类型指定动画运行多长时间(毫秒数)，默认值为400。该参数也可以为字符串"fast"(=200)或"slow"(=600)。 |
| easing        | 可选/String类型指定使用何种动画效果，默认为"swing"，还可以设为 "linear"或其他自定义的动画样式函数。 |
| complete      | 可选/Function类型元素显示完毕后需要执行的函数。函数内的`this`指向当前DOM元素。 |
| options       | Object类型指定的选项参数对象。                               |

参数`options`对象可以识别如下的属性(以下属性均是**可选**的)：

| 属性     | 属性描述                                                     |
| :------- | :----------------------------------------------------------- |
| duration | 参见参数`duration`。                                         |
| easing   | 参见参数`easing`。                                           |
| complete | 参见参数`complete`。                                         |
| queue    | Boolean类型指示是否将动画放入效果队列中，默认为`true`。从1.7版本开始，该参数可以为字符串，用于放入指定名称的效果队列。如果你指定的队列不会自动开始，你需要手动调用dequeue("queueName")来启动队列。 |

此外，jQuery 1.4 和 1.8 还为参数`options`新增了许多新的选项支持，但这些参数并不常用，此处不再赘述，详见[jQuery官方文档](http://api.jquery.com/animate/#animate-options)。

返回值

`animate()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

除了以下提到的值外，所有动画css属性都应该可以变化为一个单一的数值。使用基本的jQuery功能，大多数非数值的css属性都无法用来执行动画。例如：width、height、left、top都可用于动画，但color、background-color无法用于动画(除非使用[jQuery.Color()](https://github.com/jquery/jquery-color)插件)。除非你为属性值指定了单位(例如：px、em、%)，否则默认的数值单位为像素(px)。

速写的css属性可能无法获得完整全面的支持，例如：border、margin等，因此不推荐使用。

你还可以将css属性值设为一些特定的字符串，例如："show"、"hide"、"toggle"，则jQuery会调用该属性默认的动画形式。

此外，css属性值也可以是相对的，你可以为属性值加上前缀"+="或"-="，以便于在原来的属性值上增加或减少指定的数值。例如：`{ "height": "+=100px" }`，表示在原有高度的基础上增加100px。

请参考下面这段初始HTML代码：

*HTML:*

```html
<div id="myDiv" style="width:300px; height: 100px; background-color: #eee;">CodePlayer</div>
动画效果：
<select id="animation">
	<option value="1">动画1</option>
	<option value="2">动画2</option>
	<option value="3">动画3</option>
	<option value="4">动画4</option>
	<option value="5">动画5</option>
</select>
<input id="exec" type="button" value="执行动画" >
```

以下是与`animate()`函数相关的jQuery示例代码，以演示`animate()`函数的具体用法：

*JavaScript:*

```js
$("#exec").click( function(){
	var v = $("#animation").val();
	var $myDiv = $("#myDiv");
	if(v == "1"){
		// 数值的单位默认是px
		$myDiv.animate( { height: 200 } );
	}else if(v == "2"){
		// 在现有高度的基础上增加300px (如果原来是100px，增加后就是400px)
		// 多个动画连续执行
		$myDiv.animate( { height: "+=300px" }, "slow" ); 
		$myDiv.animate( { width: "50%" }, 1000 );		
		$myDiv.animate( { width: "200px", height: "100px" }, 1000 );		
	}else if(v == "3"){
		// font-size或fontSize均可，由多个单词构成的属性均是如此
		$myDiv.animate( { fontSize: "30px" }, 2000 );
		$myDiv.animate( { fontSize: "14px" }, 2000, function(){
			alert("动画3执行完毕!");
		});
	}else if(v == "4"){
		$myDiv.animate( { width: "50%", height: "50%" }, { duration: 2000, easing: "linear" });
	}else if(v == "5"){
		// 根据高度切换显示/隐藏，显示时高度从0增加到原高度，隐藏时高度从原高度减小到0
		$myDiv.animate( { height: "toggle" });
	}	
} );
```

## 7、jQuery.delay() 函数

`delay()`函数用于**==延迟队列中下一项的执行==**。

==`delay()`可以将队列中等待执行的下一个动画延迟指定的时间后才执行。它常用在队列中的两个jQuery效果函数之间，从而在上一个动画效果执行后延迟下一个动画效果的执行时间。==

==如果下一项不是效果动画，则它不会被加入效果队列中，因此该函数**不会对它**进行延迟调用。==

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.4 新增该函数。

*JavaScript:*

```js
jQueryObject.delay( duration [, queueName ] )
```

参数

| 参数      | 描述                                                         |
| :-------- | :----------------------------------------------------------- |
| duration  | 可选/String/Number类型指定延迟多少时间(毫秒数)，默认值为400。该参数也可以为字符串"fast"(=200)或"slow"(=600)。 |
| queueName | 可选/String类型指定的队列名称，默认为"fx"，表示jQuery标准的效果队列。 |

返回值

`delay()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>动画效果：
	<select id="animation">
		<option value="1">动画1</option>
		<option value="2">动画2</option>
		<option value="3">动画3</option>
		<option value="4">动画4</option>
	</select>
	<input id="exec" type="button" value="执行动画" >
</p>

<div id="myDiv" style="width:300px; height: 100px; background-color: #eee;">CodePlayer</div>
```

以下是与`delay()`函数相关的jQuery示例代码，以演示`delay()`函数的具体用法：

*JavaScript:*

```js
$("#exec").click( function(){
	var v = $("#animation").val();
	var $myDiv = $("#myDiv");
	if(v == "1"){
		$myDiv.slideUp( 1000 )
		.delay( "slow" )
		.fadeIn( 1500 );
	}else if(v == "2"){
		$myDiv.fadeOut( "slow" )
		.delay( 2000 )
		.slideDown( 1000 )
		.animate( { height: "+=300" } );
	}else if(v == "3"){
		/*
		注意：只有动画才会被加入效果队列中
		以下代码实际上只有slideUp()、slideDown()会加入效果队列
		delay()的延迟只对slideDown()起作用
		show()在被调用时就立即执行了(此时slideUp的动画效果尚未执行结束)
		以下代码的执行顺序时：
		1、slideUp()被加入队列、开始执行，
		2、show()也开始执行，它立即执行完毕，此时slideUp()的动画尚未执行结束
		3、延迟2秒
		4、执行SlideDown()
		*/
		$myDiv.slideUp( "slow" )
		.delay( 2000 ) 
		.show( ) // 它不是一个效果动画
		.slideDown( );
	}else if(v == "4"){
		$myDiv.show()
		.delay( 2000 )
		// 在现有高度的基础上增加300px (如果原来是100px，增加后就是400px)
		.animate( { height: "+=300px" }, 2000 ) 
		.animate( { width: "50%" }, 1000 )		
		.animate( { width: "200px", height: "100px" }, 1000 );		
	}
} );
```

## 8、jQuery.stop() 函数

`stop()`函数用于**==停止当前匹配元素上正在运行的动画==**。

==默认情况下，`stop()`函数只会停止当前正在运行的动画。如果你使用[animate()](https://codeplayer.vip/p/j7ss3)函数为当前元素设置了A、B、C这3段动画，如果当前正在执行的动画是A，则只会停止动画A的执行，不会阻止动画B和C的执行。当然，你也可以通过指定可选的选项参数来停止所有的动画。==

==停止动画并不是恢复到该动画执行前的状况，而是直接停止，当前动画执行到什么状态，就停留在什么状态。例如：执行一个元素高度从100px到200px的过渡动画，当高度为150px时停止了该动画，则当前高度仍然保持150px的现状。如果该动画设置了执行完毕后的回调函数，则不会执行该回调函数。==

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.stop( [ queueName ] [, clearQueue [, jumpToEnd ] ] )
```

参数

| 参数       | 描述                                                        |
| :--------- | :---------------------------------------------------------- |
| queueName  | 可选/String类型需要停止动画的队列名称，默认为"fx"。         |
| clearQueue | 可选/Boolean类型是否清空队列中的所有动画，默认值为`false`。 |
| jumpToEnd  | 可选/Boolean类型指示是否直接完成当前动画，默认值为`false`。 |

jQuery 1.7 新增支持：参数`queueName`。如果没有指定，则默认为"fx"，表示jQuery标准的效果队列。

如果参数`jumpToEnd`为`true`，则不再缓慢执行当前动画，而是直接完成。此时，元素将会保持动画执行完毕后的状态。

返回值

`stop()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

除了以下提到的值外，所有动画css属性都应该可以变化为一个单一的数值。使用基本的jQuery功能，大多数非数值的css属性都无法用来执行动画。例如：width、height、left、top都可用于动画，但color、background-color无法用于动画(除非使用[jQuery.Color()](https://github.com/jquery/jquery-color)插件)。除非你为属性值指定了单位(例如：px、em、%)，否则默认的数值单位为像素(px)。

速写的css属性可能无法获得完整全面的支持，例如：border、margin等，因此不推荐使用。

你还可以将css属性值设为一些特定的字符串，例如："show"、"hide"、"toggle"，则jQuery会调用该属性默认的动画形式。

此外，css属性值也可以是相对的，你可以为属性值加上前缀"+="或"-="，以便于在原来的属性值上增加或减少指定的数值。例如：`{ "height": "+=100px" }`，表示在原有高度的基础上增加100px。

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>
停止效果：
<select id="animation">
	<option value="1">停止1</option>
	<option value="2">停止2</option>
	<option value="3">停止3</option>
	<option value="4">停止4</option>
</select>
<input id="exec" type="button" value="执行动画" />
<input id="stop" type="button" value="停止动画" />
</p>
<div id="myDiv" style="width:300px; height: 100px; background-color: #eee;">CodePlayer</div>
```

以下是与`stop()`函数相关的jQuery示例代码，以演示`stop()`函数的具体用法：

*JavaScript:*

```js
$("#exec").click( function(){
	var $myDiv = $("#myDiv");
	// 在现有高度的基础上增加300px (如果原来是100px，增加后就是400px)
	$myDiv.animate( { height: "+=300px" }, 2000 ); 
	$myDiv.animate( { width: "50%" }, 1000 );		
	$myDiv.animate( { width: "200px", height: "100px" }, 1000 );		
} );

$("#stop").click( function(){
	var v = $("#animation").val();
	var $myDiv = $("#myDiv");
	if(v == "1"){
		$myDiv.stop( ); // 停止当前动画，不清空队列
	}else if(v == "2"){
		$myDiv.stop( true ); // 停止当前动画，清空队列(停止全部)
	}else if(v == "3"){
		$myDiv.stop( "fx", true ); // 等同于"2"
	}else if(v == "4"){
		$myDiv.stop( true, true ); // 清空队列，直接完成当前动画
	}
} );
```

## 9、jQuery.finish() 函数

`finish()`函数用于**==立即完成队列中的所有动画==**。

`==finish()`会停止当前正在运行的动画，删除所有队列中的动画，并完成匹配元素的所有动画。==

该函数属于`jQuery`对象(实例)。

语法

jQuery 1.9 新增该函数。

*JavaScript:*

```js
jQueryObject.finish( [ queueName ] )
```

参数

| 参数      | 描述                                                         |
| :-------- | :----------------------------------------------------------- |
| queueName | 可选/String类型指定的队列名称，默认为"fx"，表示jQuery标准的效果队列。 |

返回值

`finish()`函数的返回值为jQuery类型，返回当前jQuery对象本身。

示例&说明

请参考下面这段初始HTML代码：

*HTML:*

```html
<p>
	<input id="exec" type="button" value="执行动画" >
	<input id="finish" type="button" value="立即完成所有动画" >
</p>
<div id="myDiv" style="width:300px; height: 100px; background-color: #eee;" >CodePlayer</div>
```

以下是与`finish()`函数相关的jQuery示例代码，以演示`finish()`函数的具体用法：

*JavaScript:*

```js
$("#exec").click( function(){
    var $myDiv = $("#myDiv");
    // 在现有高度的基础上增加300px (如果原来是100px，增加后就是400px)
    $myDiv.animate( { height: "+=300px" }, 2000 ); 
    $myDiv.animate( { width: "50%" }, 1000 );       
    $myDiv.animate( { width: "200px", height: "100px" }, 1000 );        
} );

$("#finish").click( function(){
	// 无论当前动画执行到什么状态，立即完成所有动画
	// div的CSS属性直接回到动画执行完毕的最终状态(width:200px; height:100px)
    $("#myDiv").finish( );
} );
```

## 10、jQuery.fx.off 属性

`jQuery.fx.off`属性用于**==设置或返回是否全局性地禁用所有动画==**。

==如果不对该属性设置值，则返回表示是否全局性地禁用了动画效果的布尔值。==

==如果将该属性设为`true`，将全局性地禁用所有动画。所有正在执行的**动画队列**不会受到影响。尚未执行的任何动画队列都会在执行时立即完成，而不再带有动画效果。==

如果将该属性设为`false`，将全局性地启用动画效果。

你可以在遇到以下情况时，需要禁用动画效果。

- 你在配置比较低的电脑上使用jQuery。
- 某些用户可能由于动画效果而遇到了可访问性问题。

该属性属于**全局**的`jQuery`对象(也可理解为静态属性)。

语法

jQuery 1.3 新增该 静态属性。

*JavaScript:*

```js
jQuery.fx.off
```

返回值

`jQuery.fx.off`属性的返回值是Boolean类型，返回表示是否全局性地禁用了动画效果的布尔值。如果已禁用就返回`true`，否则返回`false`。

默认情况下，该属性的返回值为`false`。

示例&说明

请参考下面这段HTML示例代码：

*HTML:*

```html
<p>
	<input id="exec" type="button" value="执行动画" />
    <input id="switch" type="button" value="禁用动画效果" />
</p>
<div id="myDiv" style="width:300px; height: 100px; background-color: #eee;" >CodePlayer</div>
```

与`jQuery.fx.off`属性相关的jQuery示例代码如下：

*JavaScript:*

```js
$("#exec").click( function(){
    var $myDiv = $("#myDiv");
    // 在现有高度的基础上增加300px (如果原来是100px，增加后就是400px)
    $myDiv.animate( { height: "+=300px" }, 2000 ); 
    $myDiv.animate( { width: "50%" }, 1000 );       
    $myDiv.animate( { width: "200px", height: "100px" }, 1000 );        
} );

$("#switch").click( function(){
    // 使用jQuery.fx.off或$.fx.off均可(如果变量$是jQuery在使用的话)
	if( $.fx.off ){
		jQuery.fx.off = false; // 启用动画效果
		this.value = "禁用动画效果";
	}else{
		$.fx.off = true; // 禁用动画效果
		this.value = "启用动画效果";
	}
} );
```

## 11、jQuery.fx.interval 属性

`jQuery.fx.interval`属性用于**==设置或返回动画的帧速(毫秒值)==**。

==`jQuery.fx.interval`属性用于设置jQuery动画每隔多少毫秒绘制一帧图像(触发一次样式更改，浏览器可能会重新绘制当前页面)。==

==该值越小，则动画的触发次数越多，动画效果也更明显、更平滑，当然也就越耗费性能。==

更改该属性值时，正在执行的**动画队列**将不受影响。尚未执行的任何动画队列都将按照更改后的帧速来绘制动画效果。

该属性属于**全局**的`jQuery`对象(也可理解为静态属性)。

语法

jQuery 1.4.3 新增该 静态属性。

*JavaScript:*

```js
jQuery.fx.interval
```

返回值

`jQuery.fx.interval`属性的返回值是Number类型，返回动画的帧速(毫秒值)。

该属性的默认值为 13。

示例&说明

请参考下面这段HTML示例代码：

*HTML:*

```html
<p>
	帧速(每隔多少毫秒绘制一帧)：
	<select id="frameRate">
		<option value="5">5</option>
		<option value="10">10</option>
		<option value="13" selected="selected">默认(13)</option>
		<option value="20">20</option>
		<option value="50">50</option>
		<option value="100">100</option>
		<option value="300">300</option>
		<option value="1000">1000</option>
	</select>
	<input id="exec" type="button" value="执行动画" />
</p>
<div id="myDiv" style="width:300px; height: 100px; background-color: #ccc;" >CodePlayer</div>
```

与`jQuery.fx.interval`属性相关的jQuery示例代码如下：

*JavaScript:*

```js
// 更改帧速
$("#frameRate").change( function(){
	$.fx.interval = this.value; // 设置帧速
} );

// 执行动画
$("#exec").click( function(){
    var $myDiv = $("#myDiv");
    // 在现有高度的基础上增加300px (如果原来是100px，增加后就是400px)
    $myDiv.animate( { height: "+=300px" }, 2000 ); 
    $myDiv.animate( { width: "50%" }, 1000 );       
    $myDiv.animate( { width: "200px", height: "100px" }, 1000 );        
} );
```

# 九、AJAX

## 0、jQuery的AJAX方法

> *重要说明*：如果"版本"列的版本号带有删除线(例如： ~~1.8~~)，表示从该版本开始，此方法 **已过时**。如果版本号带有删除线，并且为红色(例如： ~~1.9~~)，表示从该版本开始，此方法已 **被移除**。

| 方法                                                     | 版本 | 描述                                                         |
| :------------------------------------------------------- | :--- | :----------------------------------------------------------- |
| ==核心方法——发送并处理AJAX请求的方法==                   |      |                                                              |
| [jQuery.ajax()](https://codeplayer.vip/p/j7ss9)          | 1.0  | 全局方法发送并处理AJAX请求。这是jQuery底层的AJAX实现，包含处理AJAX请求所需的一切功能。其他发送AJAX请求的方法都是对该方法的进一步封装。 |
| [jQuery.get()](https://codeplayer.vip/p/j7ssb)           | 1.0  | 全局方法发送并处理GET方式的AJAX请求。                        |
| [jQuery.post()](https://codeplayer.vip/p/j7ssc)          | 1.0  | 全局方法发送并处理POST方式的AJAX请求。                       |
| [jQuery.getJSON()](https://codeplayer.vip/p/j7ssd)       | 1.0  | 全局方法发送并处理GET方式、返回数据为JSON格式的AJAX请求。    |
| [jQuery.getScript()](https://codeplayer.vip/p/j7sse)     | 1.0  | 全局方法发送GET请求，用于加载一个JS脚本文件。                |
| [jQuery.load()](https://codeplayer.vip/p/j7ssa)          | 1.0  | 全局方法发送AJAX请求，用于加载一个HTML文件并替换匹配元素中的内容。 |
| ==工具方法——用于协助发送或处理AJAX请求，简化AJAX操作==   |      |                                                              |
| [jQuery.ajaxPrefilter()](https://codeplayer.vip/p/j7ssl) | 1.5  | 全局方法在$.ajax()处理参数选项之前，预处理参数选项。         |
| [jQuery.ajaxSetup()](https://codeplayer.vip/p/j7ssf)     | 1.1  | 全局方法设置$.ajax()的全局默认选项。                         |
| [jQuery.param()](https://codeplayer.vip/p/j7ssp)         | 1.0  | 全局方法将JS数组或对象序列化为字符串，以便用于URL查询字符串或AJAX请求。 |
| [serialize()](https://codeplayer.vip/p/j7ssm)            | 1.0  | 将表单元素序列化为字符串，以便用于URL查询字符串或AJAX请求。  |
| [serializeArray()](https://codeplayer.vip/p/j7ssn)       | 1.2  | 将表单元素序列化为一个JS数组。                               |
| ==事件方法——用于为AJAX事件绑定处理一个或多个函数==       |      |                                                              |
| [ajaxComplete()](https://codeplayer.vip/p/j7ssg)         | 1.0  | 设置当AJAX请求完成(无论成功或失败)时执行的处理函数。         |
| [ajaxSuccess()](https://codeplayer.vip/p/j7ssh)          | 1.0  | 设置当AJAX请求成功时执行的处理函数。                         |
| [ajaxError()](https://codeplayer.vip/p/j7ssi)            | 1.0  | 设置当AJAX请求失败时执行的处理函数。                         |
| [ajaxStart()](https://codeplayer.vip/p/j7ssj)            | 1.0  | 设置当前第一个AJAX请求开始时执行的处理函数。                 |
| [ajaxSend()](https://codeplayer.vip/p/j7st3)             | 1.0  | 设置在AJAX请求被发送前执行的处理函数。                       |
| [ajaxStop()](https://codeplayer.vip/p/j7ssk)             | 1.0  | 设置当前最后一个AJAX请求结束时执行的处理函数。               |

## 1、jQuery.ajax() 函数

`jQuery.ajax()`函数用于**==通过后台HTTP请求加载远程数据==**。

==`jQuery.ajax()`函数是jQuery封装的[AJAX技术](http://zh.wikipedia.org/zh-cn/AJAX)实现，通过该函数，我们无需刷新当前页面即可获取远程服务器上的数据。==

`jQuery.ajax()`函数是jQuery的底层AJAX实现。[jQuery.get()](https://codeplayer.vip/p/j7ssb)、 [jQuery.post()](https://codeplayer.vip/p/j7ssc)、 [load()](https://codeplayer.vip/p/j7ssa)、 [jQuery.getJSON()](https://codeplayer.vip/p/j7ssd)、 [jQuery.getScript()](https://codeplayer.vip/p/j7sse)等函数都是该函数的简化形式(都调用该函数，只是参数设置有所不同或有所省略)。

该函数属于全局`jQuery`对象(也可理解为静态函数)。

语法

jQuery 1.0 新增该静态函数。`jQuery.ajax()`函数有以下两种用法：

**用法一**：

复制

全屏

全选

*JavaScript:*

```js
jQuery.ajax( [ settings ] ] )
```

**用法二**：jQuery 1.5 新增支持该用法。

复制

全屏

全选

*JavaScript:*

```js
jQuery.ajax( url [, settings ] ] )
```

用法二是用法一的变体，它只是将参数对象`settings`中的可选属性`url`单独提取出来作为一个独立的参数。

### 参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| url      | String类型URL请求字符串。                                    |
| settings | 可选/Object类型一个Object对象，其中的每个属性用来指定发送请求所需的额外参数设置。 |

参数`settings`是一个对象，`jQuery.ajax()`可以识别该对象的以下属性(它们都是**可选**的)：

#### **accepts**Object类型

默认值：取决于`dataType`属性。

发送的内容类型请求头，用于告诉服务器——浏览器可以接收服务器返回何种类型的响应。

#### **async**Boolean类型

默认值：`true`。

指示是否是异步请求。同步请求将锁定浏览器，直到获取到远程数据后才能执行其他操作。

#### **beforeSend**Function类型

指定在请求发送前需要执行的回调函数。该函数还有两个参数：其一是`jqXHR`对象，其二是当前`settings`对象。这是一个Ajax事件，如果该函数返回`false`，将取消本次ajax请求。

#### **cache**Boolean类型

默认值：`true`(`dataType`为'script'或'jsonp'时，则默认为`false`)。

指示是否缓存URL请求。如果设为`false`将强制浏览器**不缓存**当前URL请求。该参数只对HEAD、GET请求有效(POST请求本身就不会缓存)。

#### **complete**Function/Array类型

指定请求**完成**(无论成功或失败)后需要执行的回调函数。该函数还有两个参数：一个是`jqXHR`对象，一个是表示请求状态的字符串('success'、 'notmodified'、 'error'、 'timeout'、 'abort'或'parsererror')。这是一个Ajax事件。

从jQuery 1.5开始，该属性值可以是**数组**形式的多个函数，每个函数都将被回调执行。

#### **contents**Object类型1.5 新增

一个以"{字符串:正则表达式}"配对的对象，用来确定jQuery将如何解析响应，给定其内容类型。

#### **contentType**String类型

默认值：'application/x-www-form-urlencoded; charset=UTF-8'。

使用指定的内容编码类型将数据发送给服务器。W3C的XMLHttpRequest规范规定charset始终是UTF-8，你如果将其改为其他字符集，也无法强制浏览器更改字符编码。

#### **context**Object类型

用于设置Ajax相关回调函数的上下文对象(也就是函数内的`this`指针)。

#### **converters**Object类型1.5 新增

默认值：`{'* text': window.String, 'text html': true, 'text json': jQuery.parseJSON, 'text xml': jQuery.parseXML}`。

一个数据类型转换器。每个转换器的值都是一个函数，用于返回响应转化后的值。

#### **crossDomain**Boolean类型1.5 新增

默认值：同域请求为`false`，跨域请求为`true`。

指示是否是跨域请求。如果你想在同一域中强制跨域请求(如JSONP形式)，请设置为true。例如，这允许服务器端重定向到另一个域。

#### **data**任意类型

发送到服务器的数据，它将被自动转为字符串类型。如果是GET请求，它将被附加到URL后面。

#### **dataFilter**Function类型

指定处理响应的原始数据的回调函数。该函数还有两个参数：其一表示响应的原始数据的字符串，其二是`dataType`属性字符串。

#### **dataType**String类型

默认值：jQuery智能猜测，猜测范围(xml、 json、 script或html)

指定返回的数据类型。该属性值可以为：

- 'xml' :返回XML文档，可使用jQuery进行处理。
- 'html': 返回HTML字符串。
- 'script': 返回JavaScript代码。不会自动缓存结果。除非设置了`cache`参数。注意：在远程请求时(不在同一个域下)，所有POST请求都将转为GET请求。(因为将使用DOM的script标签来加载)
- 'json': 返回JSON数据。JSON数据将使用**严格**的语法进行解析(属性名必须加双引号，所有字符串也必须用双引号)，如果解析失败将抛出一个错误。从jQuery 1.9开始，空内容的响应将返回`null`或`{}`。
- 'jsonp': JSONP格式。使用JSONP形式调用函数时，如"url?callback=?"，jQuery将自动替换第二个?为正确的函数名，以执行回调函数。
- 'text': 返回纯文本字符串。

#### **error**Function/Array类型

指定请求**失败**时执行的回调函数。该函数有3个参数：jqXHR对象、 请求状态字符串(null、 'timeout'、 'error'、 'abort'和'parsererror')、 错误信息字符串(响应状态的文本描述部分，例如'Not Found'或'Internal Server Error')。这是一个Ajax事件。跨域脚本和跨域JSONP请求**不会**调用该函数。

从jQuery 1.5开始，该属性值可以是**数组**形式的多个函数，每个函数都将被回调执行。

#### **global**Boolean类型

默认值：`true`。

指示是否触发全局Ajax事件。将该值设为`false`将阻止全局事件处理函数被触发，例如ajaxStart()和ajaxStop()。它可以用来控制各种Ajax事件。

#### **headers**Object类型1.5 新增

默认值：`{}`。

以对象形式指定附加的请求头信息。请求头`X-Requested-With: XMLHttpRequest`将始终被添加，当然你也可以在此处修改默认的XMLHttpRequest值。`headers`中的值可以覆盖`beforeSend`回调函数中设置的请求头(意即beforeSend先被调用)。

*JavaScript:*

```js
$.ajax({
	url: "my.php" ,
	headers: {
		"Referer": "https://codeplayer.vip" // 有些浏览器不允许修改该请求头
		,"User-Agent": "newLine" // 有些浏览器不允许修改该请求头
		,"X-Power": "newLine"
		,"Accept-Language": "en-US"
	}
});
```

#### **ifModified**Boolean类型

默认值：`false`。

允许当前请求仅在服务器数据改变时获取新数据(如未更改，浏览器从缓存中获取数据)。它使用HTTP头信息`Last-Modified`来判断。从jQuery 1.4开始，他也会检查服务器指定的'etag'来确定数据是否已被修改。

#### **isLocal**Boolean类型1.5.1 新增

默认值：取决于当前的位置协议。

允许将当前环境视作"本地"，(例如文件系统)，即使默认情况下jQuery不会如此识别它。目前，以下协议将被视作本地：`file`、`*-extension`和`widget`。

#### **jsonp**String类型

重写JSONP请求的回调函数名称。该值用于替代"url?callback=?"中的"callback"部分。

#### **jsonpCallback**String/Function类型

为JSONP请求指定一个回调函数名。这个值将用来取代jQuery自动生成的随机函数名。

从jQuery 1.5开始，你也可以指定一个函数来返回所需的函数名称。

#### **mimeType**String类型1.5.1 新增

一个mime类型用来覆盖XHR的mime类型。

#### **password**String类型

用于响应HTTP访问认证请求的密码。

#### **processData**Boolean类型

默认值：`true`。

默认情况下，通过`data`属性传递进来的数据，如果是一个对象(技术上讲，只要不是字符串)，都会处理转化成一个查询字符串，以配合默认内容类型 "application/x-www-form-urlencoded"。如果要发送 DOM树信息或其它不希望转换的信息，请设置为`false`。

#### **scriptCharset**String类型

设置该请求加载的脚本文件的字符集。只有当请求时dataType为"jsonp"或"script"，并且type是"GET"才会用于强制修改charset。这相当于设置<script>标签的charset属性。通常只在当前页面和远程数据的内容编码不同时使用。

#### **statusCode**Object类型1.5 新增

默认值: `{}`。

一组数值的HTTP代码和函数构成的对象，当响应时调用了相应的代码。例如：

*JavaScript:*

```js
$.ajax({
	url: a_not_found_url ,
	// 当响应对应的状态码时，执行对应的回调函数
	statusCode: {
		404: function() {
			alert( "找不到页面" );
		},
		200: function(){
			alert("请求成功");
		}
	}
});
```

#### **success**Function/Array类型

指定请求成功后执行的回调函数。该函数有3个参数：请求返回的数据、响应状态字符串、`jqXHR`对象。

从jQuery 1.5开始，该属性值可以是**数组**形式的多个函数，每个函数都将被回调执行。

#### **timeout**Number类型

设置请求超时的毫秒值。

#### **traditional**Boolean类型

如果你希望使用传统方式来序列化参数，将该属性设为`true`。

#### **type**String类型

默认值："GET"。

请求类型，可以为'POST'或'GET'。**注意**：你也可以在此处使用诸如'PUT'、'DELETE'等其他请求类型，但它们不被所有浏览器支持。

#### **url**String类型

默认值：当前页面URL。

请求的目标URL。

#### **username**String类型

用于响应HTTP访问认证请求的用户名。

#### **xhr**Function类型

默认值：在IE下是`ActiveXObject`(如果可用)，在其他浏览器中是`XMLHttpRequest`。

一个用于创建并返回XMLHttpRequest对象的回调函数。你可以重写该属性以提供自己的XHR实现，或增强其功能。

#### **xhrFields**Object类型1.5.1 新增

一个具有多个"字段名称-字段值"对的对象，用于对本地XHR对象进行设置。一对“文件名-文件值”在本机设置XHR对象。例如，如果需要，你可以用它来为跨域请求设置XHR对象的`withCredentials`属性为`true`。

*JavaScript:*

```js
$.ajax({
   url: a_cross_domain_url,
   // 将XHR对象的withCredentials设为true
   xhrFields: {
      withCredentials: true
   }
});
```

*注意*：
1、如果你的**所有AJAX请求都需要**设置`settings`中某些参数，你可以使用[jQuery.ajaxSetup()](https://codeplayer.vip/p/j7ssf)函数进行全局设置，而无需在每次执行`jQuery.ajax()`时分别设置。
2、在jQuery 1.4(含)之前，选项参数`complete`、`succes`、`error`等Ajax事件的回调函数的第3个参数不是经过jQuery封装的jqXHR对象，而是原生的XMLHttpRequest对象。

返回值

`jQuery.ajax()`函数的返回值为jqXHR类型，返回当前该请求的jqXHR对象(jQuery 1.4及以前版本返回的是原生的XMLHttpRequest对象)。

示例&说明

如果没有给`jQuery.ajax()`指定任何参数，则默认请求当前页面，并且不对返回数据进行处理。

`jQuery.ajax()`函数的`settings`对象中，常用的属性有：url、type、async、data、dataType、success、error、complete、beforeSend、timeout等。

请参考下面这段初始HTML代码：

*HTML:*

```html
<div id="content"></div>
```

以下是与`jQuery.ajax()`函数相关的jQuery示例代码，以演示`jQuery.ajax()`函数的具体用法：

*JavaScript:*

```js
$.ajax({
	 url: "jquery_ajax.php"
	, type: "POST"
	, data: "name=codeplayer&age=18"
	, success: function( data, textStatus, jqXHR ){
		// data 是返回的数据
		// textStatus 可能为"success"、"notmodified"等
		// jqXHR 是经过jQuery封装的XMLHttpRequest对象
		alert("返回的数据" + data);
	}
});


$.ajax({
	 url: "jquery_ajax.php?page=1&id=3"
	, type: "POST"
	// jQuery会自动将对象数据转换为 "name=codeplayer&age=18&uid=1&uid=2&uid=3"
	, data: { name:"codeplayer", age:18, uid: [1, 2, 3] }
	// 请求成功时执行
	, success: function( data, textStatus, jqXHR ){
		alert("返回的数据" + data);
	}
	// 请求失败时执行
	, error: function(jqXHR, textStatus, errorMsg){
		// jqXHR 是经过jQuery封装的XMLHttpRequest对象
		// textStatus 可能为： null、"timeout"、"error"、"abort"或"parsererror"
		// errorMsg 可能为： "Not Found"、"Internal Server Error"等
		alert("请求失败：" + errorMsg);
	}
});


// 将url单独提取出来作为第一个参数(jQuery 1.5+才支持)
$.ajax("jquery_ajax.php?action=type&id=3", {
	 dataType: "json" // 返回JSON格式的数据
	, success: function( data, textStatus, jqXHR ){
		// 假设返回的字符串数据为{ "name": "CodePlayer", age: 20 }
		// jQuery已帮我们将该JSON字符串转换为对应的JS对象，可以直接使用
		alert( data.name ); // CodePlayer
	}	
});


$.ajax( {
	// 注意这里有个参数callback=?
	 url: "http://cross-domain/jquery_ajax.php?name=Jim&callback=?&age=21"
	, async: false // 同步请求，发送请求后浏览器将被锁定，只有等到该请求完成(无论成功或失败)后，用户才能操作，js代码才会继续执行
	, dataType: "jsonp" // 返回JSON格式的数据
	, success: function( data, textStatus, jqXHR ){
		// 假设返回的字符串数据为{ "site_name": "CodePlayer", "site_desc": "专注于编程开发技术分享" }
		// jQuery已帮我们将该JSON字符串转换为对应的JS对象，可以直接使用
		alert( data.site_desc ); // 专注于编程开发技术分享
	}	
});


$.ajax( {
	// 加载指定的js文件到当前文档中
	 url: "http://code.jquery.com/jquery-1.8.3.min.js"
	, dataType: "script"
});
```

## 2、jQuery.get() 函数

`jQuery.get()`函数用于**==通过HTTP GET形式的AJAX请求获取远程数据==**。

==`jQuery.get()`函数用于实现简单的GET形式的AJAX请求，它在底层是使用[jQuery.ajax()](https://codeplayer.vip/p/j7ss9)来实现的，只是省略了大多数不常用的参数设置，并仅限于HTTP GET方式。==

请注意，该函数是通过**异步**方式加载数据的。

这里介绍的`jQuery.get()`是一个**全局方法**(无需创建jQuery对象即可调用，你可以理解为静态函数)。jQuery中还有一个同名的**实例方法**[get()](https://codeplayer.vip/p/j7sne)，用于获取当前jQuery对象中匹配的指定索引的DOM元素。

该函数属于全局`jQuery`对象。

语法

jQuery 1.0 新增该静态函数。

*JavaScript:*

```js
jQuery.get( url [, data ] [, success ] [, type ] )
```

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| url     | String类型指定请求的目标URL。                                |
| data    | 可选/String/Object类型发送请求传递的数据。                   |
| success | 可选/Function类型请求成功时执行的回调函数。它有3个参数：其一是请求返回的数据，其二是请求状态文本(例如"success"、 "notmodified")，其三是当前[jqXHR对象](https://codeplayer.vip/p/j7st2)(在jQuery 1.4及之前版本中，该参数为原生的XMLHttpRequest对象)。 |
| type    | 可选/String类型指定请求返回的数据类型，可以为xml、 html、 script、 json、 jsonp、text。如果省略该参数，jQuery将会根据请求进行智能猜测，猜测范围为：xml、 json、 script 或html。 |

关于参数`type`的值所表示的含义，请参考jQuery.ajax()中的[可选参数dataType](https://codeplayer.vip/p/j7ss9#dataType)。

参数`success`指定的回调函数只有在请求成功时才会执行，如果请求失败(例如找不到页面、服务器错误等)则不作任何处理。

返回值

`jQuery.get()`函数的返回值为jqXHR类型，返回发送该请求的[jqXHR对象](https://codeplayer.vip/p/j7st2)(在jQuery 1.4及之前版本中，返回的是原生的XMLHttpRequest对象)。

`jqXHR`对象是经过jQuery封装的类XMLHttpRequest对象。

示例&说明

`jQuery.get()`是`jQuery.ajax()`函数的如下简写形式：

*JavaScript:*

```js
jQuery.get(url, data, success, dataType);

// 等价于

$.ajax({
 url: url,
 type: "GET",
 data: data,
 success: success,
 dataType: dataType
});
```

请参考以下这段HTML示例代码：

*HTML:*

```html
<div id="content1">CodePlayer</div>
<div id="content2">专注于编程开发技术分享</div>
<div id="content3">https://codeplayer.vip</div>
```

以下是与`jQuery.get()`函数相关的jQuery示例代码，以演示`jQuery.get()`函数的具体用法：

*JavaScript:*

```js
// 以GET请求方式获取http://localhost/index.php?id=5的数据，但不作任何处理
$.get( "http://localhost/index.php?id=5" );


// 等价于 http://localhost/index.php?id=5&orderId=5&money=100
$.get( "http://localhost/index.php?id=5", "orderId=5&money=100" );


// 等价于 http://localhost/index.php?id=5&orderId=5&money=100
$.get( "http://localhost/index.php?id=5", {orderId: 5, money: 100} );

/* ***** 一般不会使用上述不对获取的数据作任何处理的用法***** */


// 以GET请求方式获取http://localhost/index.php?id=5的数据，将返回的html内容追加到body标签内
$.get( "http://localhost/index.php?id=5", function(data, textStatus, jqXHR){
	// data 是该请求返回的数据(可能经过处理)
    // textStatus 可能是"success"、 "notmodified"等
    // jqXHR 是经过jQuery封装的XMLHttpRequest对象(保留其本身的所有属性和方法)
    $("body").append( data );
} );


$.get( "http://localhost/index.php?id=5", { bookId: 2 }, function(data, textStatus, jqXHR){
	// 如果返回的原始文本数据为{ "name": "CodePlayer", "age": 20 }
	// 由于get()指定了返回数据的类型为JSON，则jQuery将会尝试将返回数据转换为JSON对象
	// 如果转换成功，这里的data就已经是一个js对象
	alert( data.name ); // CodePlayer
	   	
}, "json" );
```

## 3、jQuery.post() 函数

`jQuery.post()`函数用于**==通过HTTP POST形式的AJAX请求获取远程数据==**。

==`jQuery.post()`函数用于实现简单的POST形式的Ajax请求，它在底层是使用[jQuery.ajax()](https://codeplayer.vip/p/j7ss9)来实现的，只是省略了大多数不常用的参数设置，并仅限于HTTP POST方式。==

请注意，该函数是通过**异步**方式加载数据的。

该函数属于全局`jQuery`对象。

语法

jQuery 1.0 新增该静态函数。

*JavaScript:*

```js
jQuery.post( url [, data ] [, success ] [, type ] )
```

参数

| 参数    | 描述                                                         |
| :------ | :----------------------------------------------------------- |
| url     | String类型指定请求的目标URL。                                |
| data    | 可选/String/Object类型发送请求传递的数据。                   |
| success | 可选/Function类型请求成功时执行的回调函数。它有3个参数：其一是请求返回的数据，其二是请求状态文本(例如"success"、 "notmodified")，其三是当前[jqXHR对象](https://codeplayer.vip/p/j7st2)(jQuery 1.4及之前版本，该参数为原生的XMLHttpRequest对象)。 |
| type    | 可选/String类型指定请求返回的数据类型，可以为xml、 html、 script、 json、 jsonp、text。如果省略该参数，jQuery将会根据请求进行智能猜测，猜测范围为：xml、 json、 script或html。 |

关于参数`type`的值所表示的含义，请参考jQuery.ajax()中的[可选参数dataType](https://codeplayer.vip/p/j7ss9#dataType)。

参数`success`指定的回调函数只有在请求**成功**时才会执行，如果请求失败(例如找不到页面、服务器错误等)则不作任何处理。

返回值

`jQuery.post()`函数的返回值为jqXHR类型，返回发送该请求的[jqXHR对象](https://codeplayer.vip/p/j7st2)(jQuery 1.4及之前版本，返回的是原生的XMLHttpRequest对象)。

`jqXHR`对象是经过jQuery封装的类XMLHttpRequest对象。

示例&说明

`jQuery.post()`是`jQuery.ajax()`函数的如下简写形式：

*JavaScript:*

```js
jQuery.post(url, data, success, dataType);

// 等价于

$.ajax({
 url: url,
 type: "POST",
 data: data,
 success: success,
 dataType: dataType
});
```

请参考以下这段HTML示例代码：

*HTML:*

```html
<div id="content1">CodePlayer</div>
<div id="content2">专注于编程开发技术分享</div>
<div id="content3">https://codeplayer.vip</div>
```

以下是与`jQuery.post()`函数相关的jQuery示例代码，以演示`jQuery.post()`函数的具体用法：

*JavaScript:*

```js
// 以POST请求方式获取http://localhost/index.php?id=5的数据，但不作任何处理
$.post( "http://localhost/index.php?id=5" );


// 等价于 http://localhost/index.php?id=5&orderId=5&money=100
$.post( "http://localhost/index.php?id=5", "orderId=5&money=100" );


// 等价于 http://localhost/index.php?id=5&orderId=5&money=100
$.post( "http://localhost/index.php?id=5", {orderId: 5, money: 100} );

/* ***** 一般不会使用上述不对获取的POST数据作任何处理的用法***** */


// 以POST请求方式获取http://localhost/index.php?id=5的数据，将返回的html内容追加到body标签内
$.post( "http://localhost/index.php?id=5", function(data, textStatus, jqXHR){
	// data 是该请求返回的数据(可能经过处理)
	// textStatus 可能是"success"、 "notmodified"等
	// jqXHR 是经过jQuery封装的XMLHttpRequest对象(保留其本身的所有属性和方法)
	$("body").append( data );
} );


$.post( "http://localhost/index.php?id=5", { bookId: 2 }, function(data, textStatus, jqXHR){
	// 如果返回的原始文本数据为{ "name": "CodePlayer", "age": 20 }
	// 由于post()指定了返回数据的类型为JSON，则jQuery将会尝试将返回数据转换为JSON对象
	// 如果转换成功，这里的data就已经是一个js对象
	alert( data.name ); // CodePlayer
	   	
}, "json" );
```

# 十、jQuery的辅助工具属性和方法

本文列出了jQuery中几乎所有的辅助工具方法。使用这些方法可以非常简单方便地处理常见的JS代码逻辑。

例如：

- 检测用户浏览器的指定特性。
- 判断指定变量的类型。
- 操作指定DOM元素的函数队列。
- 操作指定DOM元素上的任意附加数据。
- 去除字符串两侧的连续空白字符、解析JSON字符串等。

> *版本说明*：如果"版本"列的版本号带有删除线(例如： ~~1.8~~)，表示从该版本开始，此方法 **已过时**。如果版本号带有删除线，并且为红色(例如： ~~1.9~~)，表示从该版本开始，此方法已 **被移除**。

## jQuery对象的辅助工具属性和方法

| 方法                                                         | 版本                | 描述                                                         |
| :----------------------------------------------------------- | :------------------ | :----------------------------------------------------------- |
| ==浏览器检测属性——用于检测浏览器的特性和bug信息==            |                     |                                                              |
| [jQuery.boxModel](https://codeplayer.vip/p/j7std)            | 1.0~~~1.3~~~~~1.8~~ | 检测浏览器是否使用标准盒模型渲染当前页面。请使用jQuery.support.boxModel替代。 |
| [jQuery.browser](https://codeplayer.vip/p/j7ste)             | 1.0~~~1.3~~~~~1.9~~ | 以对象形式返回用户浏览器的相关信息。                         |
| [jQuery.support](https://codeplayer.vip/p/j7stf)             | 1.3                 | 以对象形式返回用户浏览器的特性或bug信息。                    |
| ==遍历方法——用于遍历数组元素或对象属性==                     |                     |                                                              |
| [jQuery.each()](https://codeplayer.vip/p/j7snd)              | 1.0                 | 遍历对象属性或数组元素，并执行指定的回调函数。               |
| [jQuery.map()](https://codeplayer.vip/p/j7stu)               | 1.0                 | 遍历对象属性或数组元素，执行指定的回调函数，并返回以函数的返回值组成的结果数组。 |
| [jQuery.grep()](https://codeplayer.vip/p/j7stk)              | 1.0                 | 遍历对象属性或数组元素，执行指定的过滤函数，并返回过滤后的结果数组。 |
| [each()](https://codeplayer.vip/p/j7snc)                     | 1.0                 | 遍历当前jQuery对象匹配的所有DOM元素，并执行指定的回调函数。  |
| [map()](https://codeplayer.vip/p/j7so4)                      | 1.2                 | 遍历当前jQuery对象匹配的所有DOM元素，执行指定的回调函数，并返回以函数的返回值组成的结果数组。 |
| ==附加数据、函数队列操作方法==                               |                     |                                                              |
| [data()](https://codeplayer.vip/p/j7snh)                     | 1.0                 | 获取或设置匹配元素上的指定附加数据。                         |
| [removeData()](https://codeplayer.vip/p/j7sni)               | 1.0                 | 删除匹配元素上指定的附加数据。                               |
| [queue()](https://codeplayer.vip/p/j7ssq)                    | 1.2                 | 获取或设置匹配元素上的指定函数队列。                         |
| [dequeue()](https://codeplayer.vip/p/j7ssr)                  | 1.2                 | 移除每个匹配元素的指定队列中的第一个函数，并执行被移除的函数 |
| [clearQueue()](https://codeplayer.vip/p/j7sss)               | 1.4                 | 清空匹配元素上的指定函数队列。                               |
| ==扩展方法——用于扩展全局jQuery对象或jQuery实例对象的属性和方法== |                     |                                                              |
| [jQuery.extend()](https://codeplayer.vip/p/j7sth)            | 1.2                 | 扩展全局jQuery对象的属性和方法。                             |
| [jQuery.fn.extend()](https://codeplayer.vip/p/j7sti)         | 1.2                 | 扩展jQuery原型对象的属性和方法，以便于实例对象使用。         |
| ==遍历方法——用于遍历数组元素或对象属性==                     |                     |                                                              |
| [jQuery.contains()](https://codeplayer.vip/p/j7stg)          | 1.4                 | 判断指定元素内是否包含另一个元素。                           |
| [jQuery.globalEval()](https://codeplayer.vip/p/j7stj)        | 1.0.4               | 全局性地执行一段JavaScript代码。                             |
| [jQuery.inArray()](https://codeplayer.vip/p/j7stl)           | 1.2                 | 在数组中搜索指定的值，并返回其索引值。如果数组中不存在该值，则返回 -1。 |
| [jQuery.isArray()](https://codeplayer.vip/p/j7stm)           | 1.3                 | 判断指定参数是否是一个数组。                                 |
| [jQuery.isEmptyObject()](https://codeplayer.vip/p/j7stn)     | 1.4                 | 判断指定参数是否是一个空对象。                               |
| [jQuery.isPlainObject()](https://codeplayer.vip/p/j7sto)     | 1.4                 | 判断指定参数是否是一个纯粹的对象。                           |
| [jQuery.isFunction()](https://codeplayer.vip/p/j7stp)        | 1.2                 | 判断指定参数是否是一个函数。                                 |
| [jQuery.isNumeric()](https://codeplayer.vip/p/j7stq)         | 1.7                 | 判断指定参数是否是一个数字值。                               |
| [jQuery.isWindow()](https://codeplayer.vip/p/j7str)          | 1.4.3               | 判断指定参数是否是一个窗口。                                 |
| [jQuery.isXMLDoc()](https://codeplayer.vip/p/j7sts)          | 1.1.4               | 判断一个DOM节点是否位于XML文档中，或者其本身就是XML文档。    |
| [jQuery.makeArray()](https://codeplayer.vip/p/j7stt)         | 1.2                 | 将一个类数组对象转换为真正的数组对象。                       |
| [jQuery.noop()](https://codeplayer.vip/p/j7stv)              | 1.4                 | 一个空函数，它什么也不做。                                   |
| [jQuery.now()](https://codeplayer.vip/p/j7su0)               | 1.4.3               | 返回当前时间距1970年1月1日午夜所经过的毫秒数。               |
| [jQuery.parseHTML()](https://codeplayer.vip/p/j7su1)         | 1.2                 | 将HTML字符串解析为对应的DOM元素数组。                        |
| [jQuery.parseJSON()](https://codeplayer.vip/p/j7sso)         | 1.4.1               | 将格式完好的JSON字符串转为与之对应的JavaScript对象。         |
| [jQuery.parseXML()](https://codeplayer.vip/p/j7su2)          | 1.5                 | 将字符串解析为对应的XML文档。                                |
| [jQuery.trim()](https://codeplayer.vip/p/j7su4)              | 1.0                 | 去除字符串两端的空白字符。                                   |
| [jQuery.type()](https://codeplayer.vip/p/j7su5)              | 1.4.3               | 确定JavaScript内置对象的类型，并返回小写形式的类型名称。     |
| [jQuery.unique()](https://codeplayer.vip/p/j7su6)            | 1.1.3               | 根据元素在文档中出现的先后顺序对DOM元素数组进行排序，并移除重复的元素。 |

# 十一、jQuery Event对象的属性和方法

jQuery的`Event`对象用于表示当前文档元素触发的DOM事件，它对JS原生的Event对象进行了封装，从而实现跨浏览器的兼容。

该对象主要用于获取事件的相关信息，或对该事件进行处理。

*注意*：除了下列属性和方法外，jQuery的`Event`对象还具备JS原生Event对象的属性和方法。

## 1、Event 对象的属性

| 属性                                             | 初始版本 | 描述                                                   |
| :----------------------------------------------- | :------- | :----------------------------------------------------- |
| [currentTarget](https://codeplayer.vip/p/j7sq2)  | 1.3      | 返回事件冒泡阶段中的当前DOM元素。                      |
| [data](https://codeplayer.vip/p/j7sq3)           | 1.1      | 返回绑定事件时传入的附加数据。                         |
| [delegateTarget](https://codeplayer.vip/p/j7sq4) | 1.7      | 返回"受委托"调用当前事件处理函数的DOM元素。            |
| [metaKey](https://codeplayer.vip/p/j7sqk)        | 1.0.4    | 指示触发事件时是否按下了Meta键。                       |
| [namespace](https://codeplayer.vip/p/j7sq5)      | 1.4.3    | 返回触发事件时指定的命名空间。                         |
| [pageX](https://codeplayer.vip/p/j7sq6)          | 1.0.4    | 返回鼠标相对于当前文档的x坐标。                        |
| [pageY](https://codeplayer.vip/p/j7sq7)          | 1.0.4    | 返回鼠标相对于当前文档的y坐标。                        |
| [relatedTarget](https://codeplayer.vip/p/j7sq8)  | 1.1.4    | 返回事件涉及到的其它DOM元素。                          |
| [result](https://codeplayer.vip/p/j7sq9)         | 1.3      | 返回当前事件绑定的上一个事件处理函数的返回值。         |
| [target](https://codeplayer.vip/p/j7sqa)         | 1.3      | 最初触发该事件的DOM元素。                              |
| [timeStamp](https://codeplayer.vip/p/j7sqb)      | 1.2.6    | 返回事件触发的当前时间与1970年1月1日午夜之间的毫秒数。 |
| [type](https://codeplayer.vip/p/j7sqc)           | 1.0      | 返回事件的类型。例如:"click"、"focus"等。              |
| [which](https://codeplayer.vip/p/j7sqd)          | 1.1.3    | 返回触发事件时按下的鼠标按钮或键盘按键。               |

## 2、Event 对象的方法

| 方法                                                         | 初始版本 | 描述                                                         |
| :----------------------------------------------------------- | :------- | :----------------------------------------------------------- |
| [isDefaultPrevented()](https://codeplayer.vip/p/j7sqf)       | 1.3      | 是否调用了preventDefault()方法。                             |
| [isImmediatePropagationStopped()](https://codeplayer.vip/p/j7sqj) | 1.3      | 是否调用了stopImmediatePropagation()方法。                   |
| [isPropagationStopped()](https://codeplayer.vip/p/j7sqh)     | 1.3      | 是否调用了stopPropagation()方法。                            |
| [preventDefault()](https://codeplayer.vip/p/j7sqe)           | 1.0      | 阻止触发事件的默认行为。                                     |
| [stopImmediatePropagation()](https://codeplayer.vip/p/j7sqi) | 1.3      | 阻止该元素当前触发事件剩余的事件处理函数的执行，并停止事件的冒泡传递。 |
| [stopPropagation()](https://codeplayer.vip/p/j7sqg)          | 1.0      | 停止事件的冒泡传递。                                         |
