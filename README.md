# meshslam3d_sync

---
The Synchronous 3D mesh SLAM package

## requirement
- glfw
```
    sudo apt-get install libglfw3
    sudo apt-get install libglfw3-dev
```
- glad

https://glad.dav1d.de/

配置自己的gl版本，可以通过
```
    glxinfo | grep "OpenGL"
```
查看，高于3.3。下载压缩包。

glad和KHR文件夹复制到/usr/local/include/目录下，并添加glad.c文件到稍后的工程中。我这里把glad.c也放到/usr/local/include/glad/下面了。

- glm
```
    sudo apt install libglm-dev
```

- vscode 配置
1. Shader languages support for VS Code：VSCode下的shader代码高亮显示的插件。
2. GLSL Linter：用来做代码错误检查的工具。安装完插件之后还需要配置Validator path

glslangVlidator: 在github上下载release版本压缩包, 设置路径到bin下面的文件.
3. 配置代码提示：在VSCode下点击User Snippets输入glsl，之后在打开的glsl.json文件下输入[网址](https://link.zhihu.com/?target=https%3A//github.com/mdyshad0w/glslsnippets)中的内容

## learn opengl
https://learnopengl-cn.github.io/01%20Getting%20started/02%20Creating%20a%20window/

## glsl文件后缀
  ".vert": "vert", // for a vertex shader
  ".vs": "vert", // for a vertex shader
  ".frag": "frag", // for a fragment shader
  ".fs": "frag", // for a fragment shader
  ".gs": "geom", // for a geometry shader
  ".geom": "geom", // for a geometry shader
  ".comp": "comp", // for a compute shader
  ".tesc": "tesc", // for a tessellation control shader
  ".tese": "tese", // for a tessellation evaluation shader
  ".rgen": "rgen", // for a ray generation shader
  ".rint": "rint", // for a ray intersection shader
  ".rahit": "rahit", // for a ray any hit shader
  ".rchit": "rchit", // for a ray closest shader
  ".rmiss": "rmiss", // for a ray miss shader
  ".rcall": "rcall", // for a ray callable shader
  ".mesh": "mesh", // for a mesh shader
  ".task": "task" // for a task shader
