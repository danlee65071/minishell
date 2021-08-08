# minishell
Цель этого проекта - создать простую оболочку.
## Описание разрешенных функций

### char \*readline(const char \*prompt)
readline читает строку из терминала и вернет ее, используя prompt в качестве подсказки. Если prompt является NULL или пустой строкой, подсказка не выводится. Возвращенная строка выделяется с помощью malloc, вызывающий должен освободить его по завершении. В возвращаемой строке окончательный символ новой строки удален, поэтому остается только текст строки.

### void rl_clear_history(void)
Очищает список истории, удалив все записи, таким же образом, как функция clear_history () библиотеки истории. Это отличается от clear_history тем, что освобождает личные данные, которые readline сохраняет в списке истории.

### int rl_on_new_line(void)
Сообщает функциям обновления, что мы переместились на новую (пустую) строку, обычно после вывода новой строки.

### void rl_replace_line(const char \*text, int clear_undo)
Заменяет содержимое rl_line_buffer текстом text. По возможности точка и отметка сохраняются. Если clear_undo отличен от нуля, список отмены, связанный с текущей строкой, очищается.  
**Переменная char \*rl_line_buffer** - это строка, в которой содержится вся предыдущая информация, собранная до сих пор.  
**Переменная int rl_point** - смещение текущей позиции курсора в rl_line_buffer (точка).  
**Переменная int rl_mark** - метка (сохраненная позиция) в текущей строке.  

### void rl_redisplay(void)
Отображает на экране содержимое переменной rl_line_buffer.  
### void add_history (const char \*string) 
Помещает строку в конец списка истории. Связанное поле данных (если есть) установлено в NULL.   

### int printf(const char \*format, ...)
Выводит данные в соответствии с параметром format. При успешном завершении работы эти функции возвращают количество напечатанных символов (не включая завершающий '\0', использующийся для обозначения конца строки данных). Если случилась ошибка вывода, то возвратится отрицательное значение. 

### void \*malloc(size_t sizemem)
Выделяет блок памяти, размером sizemem байт, и возвращает указатель на начало блока. Содержание выделенного блока памяти не инициализируется, оно остается с неопределенными значениями. Указатель на выделенный блок памяти. Тип данных на который ссылается указатель всегда void \*, поэтому это тип данных может быть приведен к желаемому типу данных. Если функции не удалось выделить требуемый блок памяти, возвращается нулевой указатель.

### void free( void \*ptrmem)
Функция free освобождает место в памяти. Блок памяти, ранее выделенный с помощью вызова malloc, calloc или realloc освобождается. Обратите внимание, что эта функция оставляет значение ptr неизменным, следовательно, он по-прежнему указывает на тот же блок памяти, а не на нулевой указатель.

### int open(const char \*FILENAME, int FLAGS, mode_t MODE) или int open (const char \*FILENAME, int FLAGS)
Устанавливает путь к файлу или устройству. Вызов open возвращает новый дескриптор файла (всегда неотрицательное целое) в случае успешного завершения или -1 в случае неудачи. Имя открываемого файла или устройства передается как параметр FILENAME, параметр FLAGS применяется для указания действий, предпринимаемых при открытии файла, а параметр MODE определяет режим файла (по сути права доступа). Двойственность прототипа достигается благодаря механизму va_arg.

### ssize_t read (int FD, void \*BUFFER, size_t SIZE)
Этот системный вызов пытается прочитать SIZE байт из файла с дескриптором FD. Прочитанная информация заносится в BUFFER. Возвращаемое значение — число реально прочитанных байтов. В случае ошибки функция фозвращает -1. Когда текущая позиция ввода-вывода достигает конца файла, функция возвращает 0.

### int close(int FD)
Системный вызов close освобождает файловый дескриптор. Функция close возвращает 0 при удачном завершении или –1 в случае ошибки.

### pid_t fork(void)
Системный вызов fork порождает процесс методом "клонирования". Это значит, что новый процесс является точной копией своего родителя и выполняет ту же самую программу. fork возвращает PID порожденного потомка или –1 в случае ошибки.

### pid_t wait (int * EXIT_STATUS)
wait() блокирует родительский процесс до тех пор, пока не завершится один из его потомков. wait() возвращает идентификатор завершившегося потомка. EXIT_STATUS - статус завершившегося потомка.  
**Статус завершившегося потомка** — это целое число, содержащее код возврата и некоторую другую информацию о том, как завершился процесс.

### pid_t waitpid (pid_t * PID, int EXIT_STATUS, int OPTIONS)
Системный вызов waitpid() позволяет родительскому процессу ожидать конкрет- ного потомка, а не всех сразу, как это делает wait(). Этот системный вызов принимает в качестве первого аргумента идентификатор процесса, окончание работы которого следует ожидать. Аргумент EXIT_STATUS имеет тот же смысл, что и в wait(). Третий аргумент позволяет передавать в waitpid() опции, объединяемые операцией побитовой дизъюнкции. Системный вызов waitpid() возвращает идентификатор завершившегося потомка или –1 в случае ошибки.

The objective of this project is for you to create a simple shell.
