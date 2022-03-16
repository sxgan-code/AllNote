# 一、freemarker的简单使用

## 数据模型

```json
school -> {HashMap@7086} "{
	info={      
        student=张三, 
        course=[数学, 语文, 英语, 物理],
        flag1=0, 
        flag2=1, 
        flag3=1, 
        bool1=true,
		bool2=false
        }
}"
```

## 模板编写

```html
<#--            简单的map嵌套-->
    	姓名：${school.info.student}
<#--            循环list-->
        所选课程：
        <div>
            <#list school.info.course as course>
                <div>${course}</div>
            </#list>
        </div>
<#--            if判断-->
    	标志判断：
        <#if school.info.flag1 == "1">
            <div>这是Flag1的内容</div>
            </#if>
        <#if school.info.flag2 == "1">
            <div>这是Flag2的内容</div>
            </#if>
        <#if school.info.flag3 == "1">
            <div>这是Flag3的内容</div>
            </#if>

        <#if school.info.bool1 == true>
            <div>这是Bool1的内容</div>
            </#if>
        <#if school.info.bool2 == true>
            <div>这是Bool2的内容</div>
            </#if>
```

