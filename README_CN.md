# swf_reader

[中文版(当前)](README_CN.md) | [English](README.md)

> SwfLib的C++移植版本 - 用于将SWF文件解析为文档对象模型的C++库

**注意**：本项目是基于Sergey Savchuk开发的原始C#库[SwfLib](https://github.com/savchuk/SwfLib)的C++移植版本。

## 归属声明

- **原始C#实现**: 
  - 版权所有 (c) 2018 Sergey Savchuk
  - 代码库: https://github.com/SavchukSergey/SwfLib/
- **C++移植版本**: 
  - 版权所有 (c) 2024 [HYTomZ]
  - 我的网站：https://hytomz.dev/
  - 我的Github：https://github.com/HYTommm/

## 功能特性

- 将SWF文件解析为结构化的文档对象模型
- 访问单个SWF标签及其属性
- 支持 ActionScript 2.0
- 清晰、可扩展的架构，便于未来增强

**关于写入功能的说明**：本移植版本专注于SWF读取/解析功能。写入功能已被有意省略，因为已经有像[libming](https://github.com/libming/libming)这样的成熟替代方案用于SWF生成。但是，架构设计为可扩展的 - 贡献者可以独立fork并实现写入功能。

## 移植范围说明

本实现仅移植原始C#库的核心SWF读取功能。**不包含**以下组件：
- SWF写入功能
- SwfLibMill控制台应用程序
- 核心解析库之外的任何功能

## 许可证

本项目基于MIT许可证 - 详见[LICENSE](LICENSE.txt)文件。

**原始许可证**: MIT许可证，版权所有 (c) 2018 Sergey Savchuk

## 使用方法

使用示例在单独的例子文件中提供。请参阅`examples/`目录以获取详细的C++使用示例。

## 项目状态

🚧 **开发中** 🚧

此移植版本目前正在积极开发中。核心读取功能正在逐步实现。

由于SWF标签众多，我们正以愚公移山的精神不断完善，当前进度：
[#>------------------------------------------------] 3%

## 构建说明

项目成熟后将在此添加构建说明。

## 贡献指南

我们欢迎改进本库**读取/解析**功能的贡献。

**请注意**：
- 添加写入功能的拉取请求将不被接受，因为这超出了本移植的范围
- 如果您需要写入功能，请fork代码库并独立实现
- 请将贡献重点放在改进SWF解析的准确性、性能和兼容性上

## 相关项目

- [原始SwfLib (C#)](https://github.com/SavchukSergey/SwfLib/) - 原始C#实现
- [libming](https://github.com/libming/libming) - 用于SWF生成和操作的C库

---

*本项目在提供专注于读取操作的原生C++实现的同时，保持了原始SwfLib的解析功能。*