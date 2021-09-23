# 一、jQuery核心

## 1、jQuery() 函数

`jQuery()`函数是jQuery库的最核心函数，jQuery的一切都是基于此函数的。该函数==主要用于获取HTML DOM元素并将其封装为jQuery对象，以便于使用jQuery对象提供的其他属性和方法对DOM元素进行操作==。

jQuery()函数的功能非常强大，它可以将各种类型的参数智能地封装为jQuery对象。

### 语法

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

### 参数

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

### 返回值

jQuery()函数的返回值是jQuery类型，返回一个jQuery对象。

### 示例&说明

由于`jQuery()`函数较为复杂，此处将使用较大的篇幅对上述用法进行一一介绍。

#### 用法一

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

#### 用法二

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

#### 用法三

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

#### 用法四

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

#### 用法五

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

### 语法

静态函数`jQuery.noConflict()`的语法如下：

*JavaScript:*

```js
jQuery.noConflict( [ removeAll ] )
```

### 参数

| 参数      | 描述                                                         |
| :-------- | :----------------------------------------------------------- |
| removeAll | 可选/Boolean类型是否彻底移交对变量jQuery的控制权，默认为`false`。 |

如果省略了参数`removeAll`或该参数不为`true`，则表示只让出对变量`$`的控制权；如果该参数为`true`，则表示同时让出变量`$`和`jQuery`的控制权。

### 返回值

`jQuery.noConflict()`函数的返回值是jQuery类型，返回变量`jQuery`的引用。

### 示例&说明

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

### 语法

jQuery1.3 新增该属性，于jQuery 1.7被标识为已过时，并于jQuery 1.9被移除([官方文档](http://api.jquery.com/selector/)是这样描述的。不过在实际测试中发现：该属性在1.9之后的版本中仍然可用。建议谨慎使用，最好不用)。

*JavaScript:*

```js
jQueryObject.selector
```

### 返回值

`selector`属性的返回值是String类型，返回该jQuery对象的原始选择器。

如果当前jQuery对象**不是**通过传入选择器字符串来获得的，那么将返回空字符串""。

### 示例&说明

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

### 语法

jQuery1.3 新增该属性，但在==jQuery 1.10 中被标识为已过时==。保持该属性只是为了在jQuery Migrate插件中支持`live()`方法的需要，该属性可能会在未来的版本中被移除。

*JavaScript:*

```js
jQueryObject.context
```

### 返回值

`context`属性的返回值是Element类型，返回获取该jQuery对象时用于指定查找范围的DOM节点。

如果当时没有指定查找范围，则默认的查找范围为当前文档对象(document)。

`context`属性的返回值是Element类型，哪怕当时传入[jQuery(selector, context)](https://codeplayer.vip/p/j7sl8)函数的`context`参数不是Element类型。如果当时传入的`context`参数是jQuery对象，则返回该jQuery对象的`context`属性。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.length
```

### 返回值

`length`属性的返回值是Number类型，返回该jQuery对象封装的DOM元素的个数。

如果该对象是一个空的jQuery对象，没有封装任何元素，则返回0。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.size( )
```

### 返回值

`size()`函数的返回值是Number类型，返回该jQuery对象封装的DOM元素的个数。

如果该对象是一个空的jQuery对象，没有封装任何元素，则返回0。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.get( [ index ] )
//jQueryObject[index]等价于jQueryObject.get(index)，例如jQueryObject[0]等价于jQueryObject.get(0);
```

### 参数

| 参数  | 描述                                     |
| :---- | :--------------------------------------- |
| index | 可选/Number类型指定的索引，从0开始算起。 |

如果没有为`get()`函数指定参数`index`，则返回包含所有匹配到的元素的数组；如果指定了索引参数`index`，则只获取对应索引的那个元素。

如果参数`index`为负数，则将其视作`index + jQueryObject.length`。

如果参数`index`超出有效的取值范围，则返回`undefined`。

### 返回值

`get()`方法的返回值为Element/Array类型，返回包含所有匹配到的DOM元素数组或指定索引的DOM元素。

如果当前jQuery对象为空(没有匹配任何的元素)，则返回一个空的数组(不包含任何元素)。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.index( [ object ] )
```

### 参数

| 参数   | 描述                                               |
| :----- | :------------------------------------------------- |
| object | 可选/String/Element/jQuery类型表示指定元素的对象。 |

jQuery 1.4新增支持：可以不指定`object`参数、`object`参数可以为字符串(选择器)。

参数`object`可以是DOM元素、jQuery对象或字符串。如果参数`object`是字符串，则将其视作jQuery选择器，表示该选择器所匹配的元素。

### 返回值

`index()`方法的返回值为Number类型，返回指定元素的索引位置(从0开始算起)。

注意：以下文本描述中的当前元素表示当前jQuery对象的第一个元素。

- 如果没有指定参数`object`，则返回当前元素在其所有同辈元素中的索引位置。
- 如果`object`为String类型，则将其视作选择器，返回当前元素在选择器所匹配的元素中的索引位置。如果该选择器不匹配任何元素或者当前元素不在匹配到的元素内，则返回-1。
- 如果`object`为DOM元素或jQuery对象，则返回该元素(或该jQuery对象中的第一个元素)在当前jQuery对象所匹配的元素中的索引位置。

### 示例&说明

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

## 选择器一览表

### jQuery 选择器

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

### 语法

*JavaScript:*

```js
// 这里的className指的是具体的css类名
jQuery( ".className" )
```

### 参数

| 参数      | 描述                      |
| :-------- | :------------------------ |
| className | String类型指定的css类名。 |

### 返回值

返回封装了带有指定css类名的所有DOM元素的jQuery对象。

如果一个元素包含多个类，只要其中有一个类符合就可以被匹配到。

由于多个标签可以有相同的css类名，因此返回的jQuery中可能封装了多个DOM元素。如果找不到对应类名的DOM元素，则返回一个空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
// 这里的tagName指的是具体的标签名
jQuery( "tagName" )
```

### 参数

| 参数    | 描述             |
| :------ | :--------------- |
| tagName | 指定的标签名称。 |

标签名称不区分大小写。

### 返回值

返回封装了指定标签名称的DOM元素的jQuery对象。

由于一个文档中可以存在多个同名的标签，因此返回的jQuery对象内部可能封装了多个DOM元素。如果找不到对应标签名的DOM元素，则返回一个空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
// 这里的id指的是具体的id属性值
jQuery( "#id" )
```

### 参数

| 参数 | 描述                       |
| :--- | :------------------------- |
| id   | String类型指定的id属性值。 |

如果id属性值中包含特殊字符，你需要使用两个反斜杠(\)对其进行转义。

### 返回值

返回封装了指定id的DOM元素的jQuery对象。

如果有多个相同的id值，则以**第一个**id为准(HTML规范要求每个DOM元素的id值必须是唯一的，如果存在相同的id，这本身就不符合规范)。如果找不到对应id的DOM元素，则返回一个空的jQuery对象。

因此，jQuery通过id选择器最多只能选择一个DOM元素。

### 示例&说明

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

### 语法

*JavaScript:*

```js
// 这里的parent表示具体的父辈选择器
// 这里的child表示具体的子辈选择器
jQuery( "parent > child" )
```

\>号两侧的空格可以省略，但不建议省略，否则字符过于紧密可能影响阅读。

### 参数

| 参数   | 描述                                               |
| :----- | :------------------------------------------------- |
| parent | 一个有效的父辈选择器。                             |
| child  | 一个有效的子辈选择器，只用于匹配父辈选择器的子元素 |

### 返回值

返回封装了在父辈元素内查找到的符合条件的子元素的jQuery对象。

如果找不到与父辈选择器匹配的DOM元素，或者在符合父辈选择器的DOM元素内找不到符合子代选择器的子元素，则返回一个空的jQuery对象。

符合父辈选择器的父辈DOM元素可能有多个，在一个父辈DOM元素内也可能查找到多个子DOM元素，返回的jQuery对象中封装了符合条件的所有DOM元素。

### 示例&说明

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

### 语法

复制

全屏

全选

*JavaScript:*

```js
// 这里的selector表示具体的选择器
jQuery( "selector:first" )
```

### 参数

| 参数     | 描述               |
| :------- | :----------------- |
| selector | 一个有效的选择器。 |

### 返回值

返回封装了匹配选择器`selector`的第一个元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
// 这里的selector表示具体的选择器
// 这里的index表示指定的索引值
jQuery( "selector:eq(index)" )
```

### 参数

| 参数     | 描述                        |
| :------- | :-------------------------- |
| selector | 一个有效的选择器。          |
| index    | 指定的索引值，从0开始计数。 |

1.8 新增支持参数`index`可以为负数。如果`index`为负数，则将其视作`length + index`，这里的`length`指的是匹配到的元素的个数(也可以理解为从后往前计数)。

### 返回值

返回封装了匹配选择器`selector`的DOM元素中指定索引`index`处的元素的jQuery对象。

如果索引值超出有效范围，则返回空的jQuery对象。

### 示例&说明

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

### 语法

jQuery1.1.4 新增该选择器。

*JavaScript:*

```js
// 这里的selector表示具体的选择器
jQuery( "selector:first-child" )
```

### 参数

| 参数     | 描述               |
| :------- | :----------------- |
| selector | 一个有效的选择器。 |

### 返回值

返回封装了匹配作为父元素的第一个子元素的元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

jQuery先会根据选择器`selector`去查找所有匹配的元素，再判断它们是否是自己父元素的"长子"(第一个子元素)，如果是就保留，否则就舍弃掉该元素。

### 示例&说明

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

### 语法

jQuery1.1.4 新增该选择器。

*JavaScript:*

```js
// 这里的selector表示具体的选择器
// 这里的n表示具体的序号或者符合要求的表达式
jQuery( "selector:nth-child(n)" )
```

### 参数

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

### 返回值

返回封装了匹配到的元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

jQuery先会根据选择器`selector`去查找所有匹配的元素，再看它们是否是父元素的符合指定顺序的子元素，如果是就保留，否则舍弃掉该元素。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQuery( ":disabled" )
```

### 返回值

返回封装了所有不可用元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQuery( ":checked" )
```

### 返回值

返回封装了所有选中的表单域元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQuery( ":selected" )
```

### 返回值

返回封装了所有选中的option元素的jQuery对象。

如果找不到任何相应的匹配，则返回一个空的jQuery对象。

### 示例&说明

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

## jQuery对象的文档筛选方法

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

### 语法

jQuery 1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.hasClass( className )
```

### 参数

| 参数      | 描述                      |
| :-------- | :------------------------ |
| className | String类型指定的css类名。 |

### 返回值

`hasClass()`函数的返回值是Boolean类型，返回表示是否包含指定css类名的boolean值，如果包含就返回`true`，否则返回`false`。

如果当前jQuery对象匹配多个元素，只要其中有**任意一个元素**含有指定的css类名，就返回`true`。

### 示例&说明

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

### 语法

jQuery 1.1.2 新增该函数。

*JavaScript:*

```js
jQueryObject.eq( index )
```

### 参数

| 参数  | 描述                                  |
| :---- | :------------------------------------ |
| index | Number类型指定的索引值，从0开始计数。 |

jQuery 1.4 新增支持：参数`index`可以为负数。如果`index`为负数，则将其视作`length + index`，这里的`length`指的是匹配到的元素的个数(负数的`index`也可理解为从后往前计数)。

### 返回值

`eq()`函数的返回值为jQuery类型，返回封装了指定索引`index`处的元素的jQuery对象。

如果索引值超出有效范围，则返回空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.find( expr )
```

### 参数

| 参数 | 描述                                    |
| :--- | :-------------------------------------- |
| expr | String/Element/jQuery类型指定的表达式。 |

`find()`函数将在当前jQuery对象每个匹配元素的所有**后代元素**中筛选符合指定表达式的元素。

如果`expr`参数为字符串，则将其视作jQuery选择器，用以表示该选择器所匹配的元素。

jQuery 1.6 新增支持：参数`expr`可以为DOM元素(Element)或jQuery对象。

### 返回值

`find()`函数的返回值为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象匹配元素的所有符合指定选择器的**后代元素**。

如果没有匹配的元素，则返回空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.next( [ selector ] )
```

### 参数

| 参数     | 描述                                |
| :------- | :---------------------------------- |
| selector | 可选/String类型指定的选择器字符串。 |

`next()`函数将在当前jQuery对象每个匹配元素的**下一个****相邻**的**同辈**元素中筛选**符合指定选择器**的元素。

如果省略`selector`参数，则选取每个匹配元素的下一个相邻的同辈元素。

### 返回值

`next()`函数的返回值为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象所有匹配元素的下一个紧邻的符合指定选择器的同辈元素。

如果没有符合条件的元素，则返回空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.prev( [ selector ] )
```

### 参数

| 参数     | 描述                                |
| :------- | :---------------------------------- |
| selector | 可选/String类型指定的选择器字符串。 |

`prev()`函数将在当前jQuery对象每个匹配元素的**上一个****相邻**的**同辈**元素中筛选**符合指定选择器**的元素。

如果省略`selector`参数，则选取每个匹配元素的上一个相邻的同辈元素。

### 返回值

`prev()`函数的返回值为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象所有匹配元素的上一个紧邻的符合指定选择器的同辈元素。

如果没有符合条件的元素，则返回空的jQuery对象。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.siblings( [ selector ] )
```

### 参数

| 参数     | 描述                                |
| :------- | :---------------------------------- |
| selector | 可选/String类型指定的选择器字符串。 |

`siblings()`函数将在当前jQuery对象每个匹配元素的所有**同辈元素**中筛选**符合指定选择器**的元素。

如果省略`selector`参数，则选取每个匹配元素的所有同辈元素。

### 返回值

`siblings()`函数的返回值为jQuery类型，返回一个新的jQuery对象，该对象封装了当前jQuery对象每个匹配元素的所有符合指定选择器的同辈元素。

如果没有符合条件的元素，则返回空的jQuery对象。

### 示例&说明

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

### jQuery对象的文档操作方法

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
| ==CSS操作——操作文档节点的样式属性。==                        |       |                                                              |
| [css()](https://codeplayer.vip/p/j7spk)                      | 1.0   | 设置或返回元素的CSS属性。                                    |
| jQuery.cssHooks                                              | 1.4.3 | 全局属性用于设置或获取jQuery操作CSS属性的钩子。              |
| [offset()](https://codeplayer.vip/p/j7spl)                   | 1.2   | 获取鼠标相对于当前文档的坐标。                               |
| [position()](https://codeplayer.vip/p/j7spm)                 | 1.2   | 获取当前元素相对于离它最近的拥有定位的祖辈元素的坐标。       |
| [scrollTop()](https://codeplayer.vip/p/j7spn)                | 1.2.6 | 设置或返回当前元素相对于垂直滚动条顶部的偏移                 |
| [scrollLeft()](https://codeplayer.vip/p/j7spo)               | 1.2.6 | 设置或返回当前元素相对于水平滚动条最左侧的偏移               |
| [height()](https://codeplayer.vip/p/j7spp)                   | 1.0   | 设置或返回当前元素的高度值(不包括内边距、边框、外边距)。     |
| [width()](https://codeplayer.vip/p/j7spq)                    | 1.0   | 设置或返回当前元素的宽度值(不包括内边距、边框、外边距)。     |
| [innerHeight()](https://codeplayer.vip/p/j7spr)              | 1.2.6 | 设置或返回当前元素的内高度(包括内边距)。                     |
| [innerWidth()](https://codeplayer.vip/p/j7sps)               | 1.2.6 | 设置或返回当前元素的内宽度(包括内边距)。                     |
| [outerHeight()](https://codeplayer.vip/p/j7spt)              | 1.2.6 | 设置或返回当前元素的外高度(包括内边距、边框，以及可选的外边距)。 |
| [outerWidth()](https://codeplayer.vip/p/j7spu)               | 1.2.6 | 设置或返回当前元素的外宽度(包括内边距、边框，以及可选的外边距)。 |
| ==动画效果API——用于进行文档处理，并可能带有过渡的动画效果。== |       |                                                              |
| [show()](https://codeplayer.vip/p/j7srp)                     | 1.0   | 显示匹配的元素，并可选附带过渡动画效果。                     |
| [hide()](https://codeplayer.vip/p/j7srq)                     | 1.0   | 隐藏匹配的元素，并可选附带过渡动画效果。                     |
| [toggle()](https://codeplayer.vip/p/j7srr)                   | 1.0   | 切换显示/隐藏匹配的元素(如果显示就隐藏，如果隐藏就显示)，并可选附带过渡动画效果。 |
| [slideDown()](https://codeplayer.vip/p/j7srt)                | 1.0   | 显示匹配的元素，并带有向下滑动的动画效果。                   |
| [slideUp()](https://codeplayer.vip/p/j7sru)                  | 1.0   | 隐藏匹配的元素，并带有向上滑动的动画效果。                   |
| [slideToggle()](https://codeplayer.vip/p/j7srv)              | 1.0   | 切换显示/隐藏匹配的元素，并带有向下/上滑动的动画效果。       |
| [fadeIn()](https://codeplayer.vip/p/j7ss0)                   | 1.0   | 显示匹配的元素，并带有"淡入"的动画效果。                     |
| [fadeOut()](https://codeplayer.vip/p/j7ss1)                  | 1.0   | 隐藏匹配的元素，并带有"淡出"的动画效果。                     |
| [fadeToggle()](https://codeplayer.vip/p/j7ss2)               | 1.0   | 切换显示/隐藏匹配的元素，并带有"淡入"/"淡出"的动画效果。     |
| [animate()](https://codeplayer.vip/p/j7ss3)                  | 1.0   | 设置元素的CSS样式属性，并带有从当前样式到目标样式过渡的动画效果。 |
| [stop()](https://codeplayer.vip/p/j7ss4)                     | 1.2   | 停止匹配元素上当前正在运行的动画。                           |
| [delay()](https://codeplayer.vip/p/j7ss5)                    | 1.4   | 设置一个定时器，以延迟队列中下一项的执行。                   |
| [finish()](https://codeplayer.vip/p/j7ss6)                   | 1.9   | 立即完成队列中的所有动画(显示所有动画执行完后的目标样式，但省略动画过程)，并清空队列。 |
| [jQuery.fx.off](https://codeplayer.vip/p/j7ss7)              | 1.3   | 全局属性是否全局性地禁用所有动画效果。                       |
| [jQuery.fx.interval](https://codeplayer.vip/p/j7ss8)         | 1.4.3 | 全局属性设置jQuery动画的帧速(每隔多长时间绘制一帧图像)。     |
| [queue()](https://codeplayer.vip/p/j7ssq)                    | 1.2   | 创建或替换一个函数队列，或向其中添加一个队列函数。           |
| [dequeue()](https://codeplayer.vip/p/j7ssr)                  | 1.2   | 移除队列中的第一个函数，并执行该函数。                       |
| [clearQueue()](https://codeplayer.vip/p/j7sss)               | 1.4   | 清空队列中所有尚未执行的队列函数。                           |

## 1、jQuery.attr() 函数

`attr()`函数用于**==设置或返回当前jQuery对象所匹配的元素节点的属性值==**。

该函数属于`jQuery`对象(实例)。如果需要删除DOM元素节点的属性，请使用[removeAttr()](https://codeplayer.vip/p/j7snl)函数。

### 语法

`attr()`函数有以下两种用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.attr( attributeName [, value ] )
```

==设置或返回指定属性`attributeName`的值。如果指定了`value`参数，则表示设置属性`attributeName`的值为`value`；如果没有指定`value`参数，则表示返回属性`attributeName`的值==。

参数`value`还可以是函数，`attr()`将根据匹配的所有元素遍历执行该函数，函数中的`this`指针将指向对应的DOM元素。`attr()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素`attributeName`属性当前的值。函数的返回值就是为该元素的`attributeName`属性设置的值。

**用法二**：

*JavaScript:*

```js
jQueryObject.attr( object )
```

以对象形式同时设置任意多个属性的值。对象`object`的每个属性对应`attributeName`，属性的值对应`value`。*
*

*注意*：`attr()`函数的所有"设置属性"操作针对的是当前jQuery对象所匹配的**每一个**元素；所有"读取属性"的操作只针对**第一个**匹配的元素。

### 参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数          | 描述                                                         |
| :------------ | :----------------------------------------------------------- |
| attributeName | String类型指定的属性名称。                                   |
| value         | 可选/String/Function类型指定的属性值，或返回属性值的函数。   |
| object        | Object类型指定的对象，用于封装多个键值对，同时设置多项属性。 |

如果参数`value`既不是函数类型，也不是字符串类型，则会调用[toString()](https://codeplayer.vip/p/j7sgm)方法，将其转为字符串。

### 返回值

`attr()`函数的返回值是任意类型，返回值的类型取决于当前`attr()`函数执行的是"设置属性"操作还是"读取属性"操作。

如果`attr()`函数执行的是"设置属性"操作，则返回当前jQuery对象本身；如果是"读取属性"操作，则返回读取到的属性值。



如果当前jQuery对象匹配多个元素，返回属性值时，`attr()`函数只以其中第一个匹配的元素为准。如果该元素没有指定的属性，则返回`undefined`。

**prop()和attr()的主要区别**：[prop()](https://codeplayer.vip/p/j7snm)函数针对的是DOM元素(JS Element对象)的属性，`attr()`函数针对的是DOM元素所对应的文档节点的属性。详情请查看[jQuery函数attr()和prop()的区别](https://codeplayer.vip/p/j7sno)。

### 注意事项

1、`attr()`函数在操作少数属性时可能会出现异常情况，例如value和tabindex属性。

2、如果通过`attr()`函数更改<input>和<button>元素的`type`属性，在多数浏览器上将会抛出一个错误，因此该属性一般不允许在后期被更改。

3、尽量不要使用`attr()`操作表单元素的checked、selected、disabled属性。

在jQuery 1.6之前，`attr()`函数在检索某些属性(例如checked、selected、disabled等)时会考虑属性的值。以<input>元素的checked属性为例，如果该元素被选中，则返回`true`，否则(也就是没有checked属性)返回`false`。

从jQuery 1.6开始，对于没有的属性，`attr()`函数一律返回`undefined`。同样以<input>元素为例，如果该元素被选中，则`attr("checked")`返回checked(字符串)；否则(即没有checked属性)返回`undefined`。甚至在某些版本(例如1.6和1.11.1)中，`attr("checked")`只返回该元素初始化时的"checked"状态值，之后即使更改了选中状态，`attr("checked")`的返回值也不会改变。

## 2、jQuery.removeAttr() 函数

`removeAttr()`函数用于**==移除在当前jQuery对象所匹配的每一个元素节点上指定的属性==**。

该函数属于`jQuery`对象(实例)。如果你需要设置或获取元素节点上的某些属性值，你可以使用[attr()](https://codeplayer.vip/p/j7snk)函数。

### 语法

`removeAttr()`函数的语法如下：

*JavaScript:*

```js
jQueryObject.removeAttr( attributeNames )
```

*注意*：`removeAttr()`会移除当前jQuery对象所匹配的**每一个**元素上指定名称的属性。

### 参数

| 参数           | 描述                       |
| :------------- | :------------------------- |
| attributeNames | String类型指定的属性名称。 |

jQuery 1.7 新增支持：你可以传入以空格分隔的字符串，空格隔开的每个子字符串即是需要移除的属性名称。

### 返回值

`removeAttr()`函数的返回值是jQuery类型，返回当前jQuery对象本身。

在IE 6 ~ IE 8中，`removeAttr()`函数无法移除行内的`onclick`事件属性，为了避免潜在的问题，请使用[prop()](https://codeplayer.vip/p/j7snm)函数，相关代码如下：`jQueryObject.prop("onclick", null)`;

### 示例&说明

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

### 语法

jQuery 1.6 新增该函数。`prop()`函数有以下两种用法：

**用法一**：

*JavaScript:*

```js
jQueryObject.prop( propertyName [, value ] )
```

==设置或返回指定属性`propertyName`的值。如果指定了`value`参数，则表示设置属性`propertyName`的值为`value`；如果没有指定`value`参数，则表示返回属性`propertyName`的值==。

参数`value`还可以是函数，`prop()`将根据匹配的所有元素遍历执行该函数，函数中的`this`指针将指向对应的DOM元素。`prop()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素`propertyName`属性当前的值。函数的返回值就是为该元素的`propertyName`属性设置的值。

**用法二**：

*JavaScript:*

```js
jQueryObject.prop( object )
```

以对象形式同时设置任意多个属性的值。对象`object`的每个属性对应`propertyName`，属性的值对应`value`。

*注意*：`prop()`函数的所有"设置属性"操作针对的是当前jQuery对象所匹配的**每一个**元素；所有"读取属性"的操作只针对**第一个**匹配的元素。

### 参数

请根据前面语法部分所定义的参数名称查找对应的参数。

| 参数         | 描述                                                         |
| :----------- | :----------------------------------------------------------- |
| propertyName | String类型指定的属性名称。                                   |
| value        | 可选/Object/Function类型指定的属性值，或返回属性值的函数。   |
| object       | Object类型指定的对象，用于封装多个键值对，同时设置多项属性。 |

参数`value`可以是包括对象和数组在内的任意类型。

### 返回值

`prop()`函数的返回值是任意类型，返回值的类型取决于当前`prop()`函数执行的是"设置属性"操作还是"读取属性"操作。

如果`prop()`函数执行的是"设置属性"操作，则返回当前jQuery对象本身；如果是"读取属性"操作，则返回读取到的属性值。

如果当前jQuery对象匹配多个元素，返回属性值时，`prop()`函数只以其中第一个匹配的元素为准。如果该元素没有指定的属性，则返回`undefined`。

**prop()和attr()的主要区别**：`prop()`函数针对的是DOM元素(JS Element对象)的属性，[attr()](https://codeplayer.vip/p/j7snk)函数针对的是DOM元素所对应的文档节点的属性。详情请查看[jQuery函数attr()和prop()的区别](https://codeplayer.vip/p/j7sno)。

### 注意事项

1、如果通过`prop()`函数更改<input>和<button>元素的`type`属性，在多数浏览器上将会抛出一个错误，因为该属性一般不允许在后期更改。

2、如果使用`prop()`函数操作表单元素的checked、selected、disabled等属性，如果该元素被选中(或禁用)，则返回`true`，否则(意即HTML中没有该属性)返回`false`。

3、`prop()`函数还可以设置或返回DOM元素的`Element`对象上的某些属性，例如：tagName、selectedIndex、nodeName、nodeType、ownerDocument、defaultChecked和defaultSelected等属性。

4、在IE9及更早版本中，如果使用`prop()`函数设置的属性值不是一个简单的原始值(String、Number、Boolean)，并且在对应的DOM元素被销毁之前，该属性没有被移除，则可能会导致内存泄漏问题。如果你只是为了存储数据，建议你使用[data()](https://codeplayer.vip/p/j7snh)函数，以避免内存泄漏问题。

### 示例&说明

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

#### 4.1、操作对象不同

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

#### 4.2、应用版本不同

`attr()`是jQuery 1.0版本就有的函数，`prop()`是jQuery 1.6版本新增的函数。毫无疑问，在1.6之前，你只能使用`attr()`函数；1.6及以后版本，你可以根据实际需要选择对应的函数。

#### 4.3、用于设置的属性值类型不同

==由于`attr()`函数操作的是文档节点的属性，因此设置的属性值只能是字符串类型，如果不是字符串类型，也会调用其[toString()](https://codeplayer.vip/p/j7sgm)方法，将其转为字符串类型。==

==`prop()`函数操作的是JS对象的属性，因此设置的属性值可以为包括数组和对象在内的任意类型。==

#### 4.4、其他细节问题

在jQuery 1.6之前，只有`attr()`函数可用，该函数不仅承担了attribute的设置和获取工作，还同时承担了property的设置和获取工作。例如：在jQuery 1.6之前，`attr()`也可以设置或获取tagName、className、nodeName、nodeType等DOM元素的property。

直到jQuery 1.6新增`prop()`函数，并用来承担property的设置或获取工作之后，`attr()`才只用来负责attribute的设置和获取工作。

此外，对于表单元素的checked、selected、disabled等属性，在jQuery 1.6之前，`attr()`获取这些属性的返回值为Boolean类型：如果被选中(或禁用)就返回`true`，否则返回`false`。

但是从1.6开始，使用`attr()`获取这些属性的返回值为String类型，如果被选中(或禁用)就返回checked、selected或disabled，否则(即元素节点没有该属性)返回`undefined`。并且，在某些版本中，这些属性值表示文档加载时的初始状态值，即使之后更改了这些元素的选中(或禁用)状态，对应的属性值也不会发生改变。

#### 4.5、重点：

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

### 语法

*JavaScript:*

```js
jQueryObject.addClass( classNames )
```

*注意*：`addClass()`会为当前jQuery对象所匹配的**每一个**元素添加指定的css类名。

### 参数

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| classNames | String/Function类型指定的css类名，字符串可以通过空格分隔的方式来添加多个css类名。或者为返回css类名的函数 |

jQuery 1.4 新增支持：参数`classNames`可以为函数。`addClass()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`addClass()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素节点当前的class属性值。

函数的返回值就是为该元素添加的css类名(也可以通过空格分隔表示多个css类名)。如果返回值为空白字符串或者`undefined`，`addClass()`将不会为当前元素添加任何css类名。

### 返回值

`addClass()`函数的返回值是jQuery类型，返回当前jQuery对象本身。

==`addClass()`函数只是在原有css类名的基础上，添加新的css类名，并不会覆盖掉之前已存在的css类名。如果待添加的css类名已经存在，`addClass()`并不会重复添加。==

### 示例&说明

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

### 语法

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

### 参数

| 参数       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| classNames | String/Function类型指定的css类名，字符串可以通过空格分隔的方式来添加多个css类名。或者为返回css类名的函数。 |
| switch     | Boolean类型一个布尔值，用于指定是添加还是移除css类名。`true`表示添加，`false`表示移除。 |

jQuery 1.4 新增支持：参数`className`可以为函数。`toggleClass()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`toggleClass()`还会为函数传入3个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素节点当前的class属性值，第三个参数就是调用`toggleClass()`时传入的`switch`参数。

函数的返回值就是该元素需要切换的css类名(也可以通过空格分隔表示多个css类名)。如果返回值为空白字符串或者`undefined`，`toggleClass()`将不会为当前元素切换任何css类名。

### 返回值

`toggleClass()`函数的返回值是jQuery类型，返回当前jQuery对象本身。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.html( [ htmlString ] )
```

### 参数

| 参数       | 描述                                           |
| :--------- | :--------------------------------------------- |
| htmlString | 可选/String/Function类型用于设置的html字符串。 |

如果没有指定`htmlString`参数，则表示获取**第一个匹配元素**的html内容；如果指定了`htmlString`参数，则表示设置**所有匹配元素**的html内容。

jQuery 1.4 新增支持：参数`htmlString`可以为函数。`html()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`html()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素当前的html内容。函数的返回值就是需要为该元素设置的html内容。

如果参数`htmlString`不是字符串或函数类型，则会被转换为字符串类型( [toString()](https://codeplayer.vip/p/j7sgm) )。如果参数为`null`或`undefined`，则将其视作空字符串("")。

### 返回值

`html()`函数的返回值是String/jQuery类型，返回值的实际类型取决于`html()`函数所执行的操作。

如果`html()`函数执行的是设置操作，将返回当前jQuery对象本身。如果执行的是获取操作，将返回第一个匹配元素的html内容，该值为字符串类型。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.text( [ textString ] )
```

### 参数

| 参数       | 描述                                           |
| :--------- | :--------------------------------------------- |
| textString | 可选/String/Function类型用于设置的text字符串。 |

如果没有指定`textString`参数，则表示获取合并了**每一个匹配元素**中的内容后的text内容；如果指定了`textString`参数，则表示设置**所有匹配元素**的text内容。

jQuery 1.4 新增支持：参数`textString`可以为函数。`text()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。



`text()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素当前的text内容。函数的返回值就是需要为该元素设置的text内容。

如果参数`textString`不是字符串或函数类型，则会被转换为字符串类型( [toString()](https://codeplayer.vip/p/j7sgm) )。如果参数为`null`或`undefined`，则将其视作空字符串("")。

### 返回值

`text()`函数的返回值是String/jQuery类型，返回值的实际类型取决于`text()`函数所执行的操作。

如果`text()`函数执行的是设置操作，将返回当前jQuery对象本身。如果执行的是获取操作，将返回合并了每一个匹配元素中的内容后的text内容，该值为字符串类型。

### 示例&说明

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

### 语法

*JavaScript:*

```js
jQueryObject.val( [ values ] )
```

### 参数

| 参数   | 描述                                              |
| :----- | :------------------------------------------------ |
| values | 可选/String/Array/Function类型用于设置的value值。 |

如果没有指定`values`参数，则表示获取**第一个匹配元素**的value值；如果指定了`value`参数，则表示设置**所有匹配元素**的value值。

jQuery 1.4 新增支持：参数`values`可以为函数。`val()`将根据匹配的所有元素遍历执行该函数，函数中的`this`将指向对应的DOM元素。

`val()`还会为函数传入两个参数：第一个参数就是该元素在匹配元素中的索引，第二个参数就是该元素当前的value属性值。函数的返回值就是需要为该元素设置的value值。

如果参数`values`为`null`或`undefined`，则将其视作空字符串("")。如果参数`values`不是字符串或函数类型，并且当前元素不是多选的选择框(多选选择框会特殊处理数组类型)，则其他类型的值均会被转换为字符串( [toString()](https://codeplayer.vip/p/j7sgm) )。

### 返回值

`val()`函数的返回值是String/Array/jQuery类型，返回值的实际类型取决于`val()`函数所执行的操作。

如果`val()`函数执行的是设置操作，将返回当前jQuery对象本身。如果执行的是获取操作，将返回第一个匹配元素的value属性值，该值一般为字符串类型；如果该元素是多选的<select>元素，则返回包含所有选中值的数组。

### 示例&说明

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

