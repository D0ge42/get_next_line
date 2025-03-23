# Get_Next_Line - 42 Project (125/100)

**Get_Next_Line** is a project developed as part of the **42 School** curriculum. It is a function that reads a line from a file descriptor **efficiently**, handling multiple file descriptors simultaneously. This implementation **passed all Moulinette tests** and achieved a **125/100 score**, ensuring a **leak-free, optimized, and robust** solution. 🚀

---

## 🌟 Features
- **Reads a line from a file descriptor efficiently**
- **Supports multiple file descriptors at the same time**
- **Handles any buffer size (`BUFFER_SIZE`)**
- **Optimized for performance & minimal memory usage**
- **No memory leaks & bulletproof implementation**
- **Bonus features fully integrated**

---

## 🛠️ Compilation & Usage
### 🔧 Build
Compile with:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### 🚀 Function Prototype
```c
char *get_next_line(int fd);
```

### 🏆 Example Usage
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 📖 How It Works
1. **Reads from the file descriptor until a newline (`\n`) is found.**
2. **Stores leftover characters for future calls.**
3. **Efficiently manages memory to avoid leaks.**
4. **Works with multiple file descriptors simultaneously.**

---

## 🏆 Why This Get_Next_Line?
✅ **Fully tested & verified** (125/100 Moulinette score)  
✅ **Handles all edge cases** (EOF, multiple FDs, large/small `BUFFER_SIZE`)  
✅ **Optimized for performance**  
✅ **Memory-leak free & bulletproof implementation**  
✅ **Bonus features fully integrated**  

---

## 📜 License
This project is open-source and free to use for educational purposes.

---

Efficient file reading with **Get_Next_Line**! 📄⚡

