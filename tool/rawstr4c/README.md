<!-- -----------------------------------------------------------
 ! SPDX-License-Identifier: GFDL-1.3-or-later
 ! -------------------------------------------------------------
 ! Doc Type      : Markdown
 ! Doc Name      : (rawstr4c configuration).md
 ! Doc Authors   : Aoran Zeng <ccmywish@qq.com>
 ! Contributors  :  Nul None  <nul@none.org>
 !               |
 ! Created On    : <2025-07-12>
 ! Last Modified : <2025-07-16>
 ! ---------------------------------------------------------- -->

# rawstr4c

当你需要写一个复杂的C语言字符串的时候，可使用该工具

出于方便，我们仅使用 `just` 来调用

```bash
cd src/recipe

# 尽管我们已经在 recipe 目录中了，但是 just 自己会重新切换到项目根目录，所以我们总是给一个相对根目录的路径
just rawstr4c ./src/recipe/ware
```

<br>



## Convention

一个配置文件，应使用这样的顺序:

- section 标题
- 对该变量的说明
- 配置块 configblock
- 配置块 configblock 注释
- 代码块 codeblock (raw string)
- 代码块 codeblock 内容的注释

<br>



## 配置语法

```markdown

- config-item1 = `:mode`

- config-item2 = `true|false|yes|no`

- config-item3 = `string value`

```

配置项总是以 `-` 开头，配置项名称后跟一个 `=`，右值必须使用 ``` `` ``` 来包裹

注意，如果值并非是由用户随意给出，则应该设置为 mode 类型，使用 `:` 作为前缀

<br>



## 配置项

注意，如非特殊说明，第一项为默认值

- output =

  - `:terminal` = 在终端输出
  - `:macro` = 输出为一个 `.h` 文件，定义为宏
  - `:global-variable` = 输出一个 `.h` 文件和对应的 `.c` 文件，定义为全局变量
  - `:global-variable-only-header` = 仅输出为一个 `.h` 文件，定义为全局变量

- ~~output-file~~ = (暂未实现)

  自定义生成的头文件名，默认值为 `rawstr4c.h`

- translate =

  - `:escape` = 仅转义
  - `:oct` = 八进制
  - `:hex` = 十六进制

- postfix =

  - `:use-language` = 使用 codeblock 的语言
  - `your string` = 使用某一自定义字符串为后缀

- name =

  生成的变量名，默认将会包含前缀和后缀。如果没有给该配置项，将会使用该节标题

- name-literally = `false` | `true`

  无视其他配置项，直接使用 `name` 作为变量名

- namespace =

  将作为变量名 `name` 之前 `prefix` 之后的前缀，将影响下一层级的 section

- keep-prefix = `true` | `false`

  变量名是否使用前缀

- keep-postfix = `true` | `false`

  变量名是否使用后缀
