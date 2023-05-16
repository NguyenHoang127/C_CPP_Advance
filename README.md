# C_CPP_Anvanced
## Lesson 1: Complier
- Quá trình xử lý file .C sang file .exe
  + File .c là file source và file .h là file header
  
  + Preprocessor quá trình tiền xử lý build thành file .I gọi là preprocessed source
  + gcc -E B1_Complier.c -o  B1_Complier.i

  + Compiler từ file.I thành file.s gọi là Assemply code
  + gcc B1_Complier.i -S -o main.s

  + Assembler tạo ra file object file .o +library
  + Linker tạo ra chương trình executable .exe
