# swf_reader

[中文版](README_CN.md) | [English(this)](README.md)

> C++ port of SwfLib - A C++ library for reading SWF files into Document Object Model

**Note**: This is a C++ translation/port of the original C# library [SwfLib](https://github.com/SavchukSergey/SwfLib/) by Sergey Savchuk.

## Attribution

- **Original C# implementation**: 
  - Copyright (c) 2018 Sergey Savchuk
  - Repository: https://github.com/SavchukSergey/SwfLib/
- **C++ port**: 
  - Copyright (c) 2025 HYTomZ
  - MY Wibsite: https://hytomz.dev/
  - My GitHub: https://github.com/HYTommm/

## Features

- Parse SWF files into a structured Document Object Model
- Access individual SWF tags and their properties
- Supports ActionScript 2.0
- Clean, extensible architecture for future enhancements

**Note on Write Functionality**: This port focuses exclusively on SWF reading/parsing capabilities. Write functionality has been intentionally omitted as robust alternatives like [libming](https://github.com/libming/libming) already exist for SWF generation. However, the architecture is designed to be extensible - contributors may fork and implement write functionality independently.

## Scope of This Port

This implementation ports only the core SWF reading functionality from the original C# library. The following components are **not included**:
- SWF writing capabilities
- SwfLibMill console application
- Any functionality beyond the core parsing library

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.

**Original License**: MIT License, Copyright (c) 2018 Sergey Savchuk

## Usage

Usage examples are provided in separate example files. Please refer to the `examples/` directory for detailed C++ usage examples.

## Project Status

🚧 **Under Development** 🚧

This port is currently in active development. The core reading functionality is being implemented incrementally.

Due to the large number of SWF tags, we are constantly improving the library with the spirit of the "Foolish Old Man Removes the Mountains". Current progress:
[#>------------------------------------------------] 3%

## Building

Build instructions will be added here as the project matures.

## Contributing

We welcome contributions that improve the **reading/parsing** functionality of this library.

**Please note**: 
- Pull requests adding write functionality will not be accepted, as this is outside the scope of this port
- If you need write capabilities, please fork the repository and implement them independently
- Focus your contributions on improving SWF parsing accuracy, performance, and compatibility

## Related Projects

- [Original SwfLib (C#)](https://github.com/SavchukSergey/SwfLib/) - The original C# implementation
- [libming](https://github.com/libming/libming) - C/C++ library for SWF generation and manipulation

---

*This project maintains the parsing functionality of the original SwfLib while providing a native C++ implementation focused exclusively on read operations.*