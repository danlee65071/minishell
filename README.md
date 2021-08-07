# minishell
Цель этого проекта - создать простую оболочку.
## Описание разрешенных функций

### char \*readline(const char \*prompt)
readline читает строку из терминала и вернет ее, используя prompt в качестве подсказки. Если prompt является NULL или пустой строкой, подсказка не выводится. Возвращенная строка выделяется с помощью malloc, вызывающий должен освободить его по завершении. В возвращаемой строке окончательный символ новой строки удален, поэтому остается только текст строки. Необходимые библиотеки: <stdio.h>, <readline/readline.h>, <readline/history.h>.

### void rl_clear_history(void)
Очищает список истории, удалив все записи, таким же образом, как функция clear_history () библиотеки истории. Это отличается от clear_history тем, что освобождает личные данные, которые readline сохраняет в списке истории. Необходимые библиотеки: <stdio.h>, <readline/readline.h>, <readline/history.h>.

### int rl_on_new_line(void)
Сообщает функциям обновления, что мы переместились на новую (пустую) строку, обычно после вывода новой строки. Необходимые библиотеки: <stdio.h>, <readline/readline.h>, <readline/history.h>.

### void rl_replace_line(const char \*text, int clear_undo)
Заменяет содержимое rl_line_buffer текстом text. По возможности точка и отметка сохраняются. Если clear_undo отличен от нуля, список отмены, связанный с текущей строкой, очищается.  
**Переменная char \*rl_line_buffer** - это строка, в которой содержится вся предыдущая информация, собранная до сих пор.  
**Переменная int rl_point** - смещение текущей позиции курсора в rl_line_buffer (точка).  
**Переменная int rl_mark** - метка (сохраненная позиция) в текущей строке.  
Необходимые библиотеки: <stdio.h>, <readline/readline.h>, <readline/history.h>.  

### void rl_redisplay(void)
Отображает на экране содержимое переменной rl_line_buffer. Необходимые библиотеки: <stdio.h>, <readline/readline.h>, <readline/history.h>.  

The objective of this project is for you to create a simple shell.
