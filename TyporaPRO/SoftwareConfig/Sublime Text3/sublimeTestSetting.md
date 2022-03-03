```json
{
    //禁用更新
    "update_check": false,
    // ***主题文件的路径***
    "color_scheme": "Packages/Color Scheme - Default/Monokai.sublime-color-scheme",
    // ***设置字体和大小，必须在Settings-User里重写，这里设置没有任何效果***
    "font_face": "Consolas",
    "font_size": 14,

    "theme": "Default.sublime-theme",
    //是否显示行号
    "line_numbers": true,
    // ***是否显示代码折叠按钮***
    "fold_buttons": true,
    //拼写检查
    "spell_check": false,
    // ***代码提示***
    "auto_complete": true,
    // ***代码提示延迟显示***
    "auto_complete_delay": 50,
    // ***默认编码格式***
    "default_encoding": "UTF-8",
    // ***行号边栏和文字的间距***
    "margin": 2,
    // ***Tab键制表符宽度***
    "tab_size": 4,
    // ***自动匹配引号，括号等***
    "auto_match_enabled": true,
    // ***突出显示当前光标所在的行***
    "highlight_line": true,
    // ***设置光标闪动方式***
    "caret_style": "smooth",
    // ***是否特殊显示当前光标所在的括号、代码头尾闭合标记***
    "match_brackets": true,
    // ***是否突出显示圆括号，match_brackets为true生效***
    "match_brackets_square": false,

    // ***是否突出显示大括号，match_brackets为true生效\***
    "match_brackets_braces": false,
    // ***是否突出显示尖括号，match_brackets为true生效***
    "match_brackets_angle": false,
    // ***html和xml下突出显示光标所在标签的两端，影响HTML、XML、CSS等***
    "match_tags": true,

    // ***全文突出显示和当前选中字符相同的字符***
    "match_selection": true,

    // ***设置每一行到顶部，以像素为单位的间距，效果相当于行距***
    "line_padding_top": 1,

    // ***设置每一行到底部，以像素为单位的间距，效果相当于行距***
    "line_padding_bottom": 1,
    // ***制表位的对齐白线是否显示，颜色可在主题文件里设置（guide，activeGuide，stackGuide）***
    "draw_indent_guides": true,
    // ***选中的文本按Ctrl + f时，自动复制到查找面板的文本框里***
    "find_selected_text": true,
    // ***哪些文件会被显示到边栏上***
    "folder_exclude_patterns": [".svn", ".git", ".hg", "CVS"],
    "file_exclude_patterns": ["*.pyc", "*.pyo", "*.exe", "*.dll", "*.obj","*.o", "*.a", "*.lib", "*.so", "*.dylib", "*.ncb", "*.sdf", "*.suo", "*.pdb", "*.idb", ".DS_Store", "*.class", "*.psd", "*.db"],
    // These files will still show up in the side bar, but won't be included in
    // Goto Anything or Find in Files
    "binary_file_patterns": ["*.jpg", "*.jpeg", "*.png", "*.gif", "*.ttf", "*.tga", "*.dds", "*.ico", "*.eot", "*.pdf", "*.swf", "*.jar", "*.zip"],
    // 退出时，关闭所有文件
    "hot_exit": false,
    "remember_open_files":false,

}
```

