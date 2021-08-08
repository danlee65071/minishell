# minishell

# Содержание
1. [Описание разрешенных функций](#funcs_description)
    * [readline](#readline_func)
    * [rl_clear_history](#rl_clear_history)
    * [rl_on_new_line](#rl_on_new_line)
    * [rl_replace_line](#rl_replace_line)
    * [rl_redisplay](#rl_redisplay)
    * [add_history](#add_history)
    * [printf](#printf)
    * [malloc](#malloc)
    * [free](#free)
    * [open](#open)
    * [read](#read)
    * [close](#close)
    * [fork](#fork)
    * [wait](#wait)
    * [waitpid](#waitpid)
    * [wait3 и wait4](#wait_3_4)
    * [signal](#signal)
    * [kill](#kill)
    * [exit](#exit)
    * [getcwd](#getcwd)
    * [chdir](#chdir)
    * [stat, fstat и lstat](#stat)
    * [unlink](#unlink)
    * [execve](#execve)
    * [dup и dup2](#dup)
    * [pipe](#pipe)
    * [opendir](#opendir)
    * [readdir](#readdir)
    * [strerror](#strerror)
    * [errno](#errno)
    * [isatty](#isatty)
    * [ttyname](#ttyname)
    * [ttyslot](#ttyslot)

## Описание разрешенных функций <a name = "funcs_description"></a>

### char \*readline(const char \*prompt) <a name = "readline_func"></a>
readline читает строку из терминала и вернет ее, используя prompt в качестве подсказки. Если prompt является NULL или пустой строкой, подсказка не выводится. Возвращенная строка выделяется с помощью malloc, вызывающий должен освободить его по завершении. В возвращаемой строке окончательный символ новой строки удален, поэтому остается только текст строки.

### void rl_clear_history(void) <a name = "rl_clear_history"></a>
Очищает список истории, удалив все записи, таким же образом, как функция clear_history () библиотеки истории. Это отличается от clear_history тем, что освобождает личные данные, которые readline сохраняет в списке истории.

### int rl_on_new_line(void) <a name = "rl_on_new_line"></a>
Сообщает функциям обновления, что мы переместились на новую (пустую) строку, обычно после вывода новой строки.

### void rl_replace_line(const char \*text, int clear_undo) <a name = "rl_replace_line"></a>
Заменяет содержимое rl_line_buffer текстом text. По возможности точка и отметка сохраняются. Если clear_undo отличен от нуля, список отмены, связанный с текущей строкой, очищается.  
**Переменная char \*rl_line_buffer** - это строка, в которой содержится вся предыдущая информация, собранная до сих пор.  
**Переменная int rl_point** - смещение текущей позиции курсора в rl_line_buffer (точка).  
**Переменная int rl_mark** - метка (сохраненная позиция) в текущей строке.  

### void rl_redisplay(void) <a name = "rl_redisplay"></a>
Отображает на экране содержимое переменной rl_line_buffer.  

### void add_history(const char \*string) <a name = "add_history"></a>
Помещает строку в конец списка истории. Связанное поле данных (если есть) установлено в NULL.   

### int printf(const char \*format, ...) <a name = "printf"></a>
Выводит данные в соответствии с параметром format. При успешном завершении работы эти функции возвращают количество напечатанных символов (не включая завершающий '\0', использующийся для обозначения конца строки данных). Если случилась ошибка вывода, то возвратится отрицательное значение. 

### void \*malloc(size_t sizemem) <a name = "malloc"></a>
Выделяет блок памяти, размером sizemem байт, и возвращает указатель на начало блока. Содержание выделенного блока памяти не инициализируется, оно остается с неопределенными значениями. Указатель на выделенный блок памяти. Тип данных на который ссылается указатель всегда void \*, поэтому это тип данных может быть приведен к желаемому типу данных. Если функции не удалось выделить требуемый блок памяти, возвращается нулевой указатель.

### void free( void \*ptrmem) <a name = "free"></a>
Функция free освобождает место в памяти. Блок памяти, ранее выделенный с помощью вызова malloc, calloc или realloc освобождается. Обратите внимание, что эта функция оставляет значение ptr неизменным, следовательно, он по-прежнему указывает на тот же блок памяти, а не на нулевой указатель.

### int open(const char \*FILENAME, int FLAGS, mode_t MODE) или int open (const char \*FILENAME, int FLAGS) <a name = "open"></a>
Устанавливает путь к файлу или устройству. Вызов open возвращает новый дескриптор файла (всегда неотрицательное целое) в случае успешного завершения или -1 в случае неудачи. Имя открываемого файла или устройства передается как параметр FILENAME, параметр FLAGS применяется для указания действий, предпринимаемых при открытии файла, а параметр MODE определяет режим файла (по сути права доступа). Двойственность прототипа достигается благодаря механизму va_arg.

### ssize_t read (int FD, void \*BUFFER, size_t SIZE) <a name = "read"></a>
Этот системный вызов пытается прочитать SIZE байт из файла с дескриптором FD. Прочитанная информация заносится в BUFFER. Возвращаемое значение — число реально прочитанных байтов. В случае ошибки функция фозвращает -1. Когда текущая позиция ввода-вывода достигает конца файла, функция возвращает 0.

### int close(int FD) <a name = "close"></a>
Системный вызов close освобождает файловый дескриптор. Функция close возвращает 0 при удачном завершении или –1 в случае ошибки.

### pid_t fork(void) <a name = "fork"></a>
Системный вызов fork порождает процесс методом "клонирования". Это значит, что новый процесс является точной копией своего родителя и выполняет ту же самую программу. fork возвращает PID порожденного потомка или –1 в случае ошибки.

### pid_t wait (int \*EXIT_STATUS) <a name = "wait"></a>
wait() блокирует родительский процесс до тех пор, пока не завершится один из его потомков. wait() возвращает идентификатор завершившегося потомка. EXIT_STATUS - статус завершившегося потомка.  
**Статус завершившегося потомка** — это целое число, содержащее код возврата и некоторую другую информацию о том, как завершился процесс.

### pid_t waitpid (pid_t * PID, int EXIT_STATUS, int OPTIONS) <a name = "waitpid"></a>
Системный вызов waitpid() позволяет родительскому процессу ожидать конкрет- ного потомка, а не всех сразу, как это делает wait(). Этот системный вызов принимает в качестве первого аргумента идентификатор процесса, окончание работы которого следует ожидать. Аргумент EXIT_STATUS имеет тот же смысл, что и в wait(). Третий аргумент позволяет передавать в waitpid() опции, объединяемые операцией побитовой дизъюнкции. Системный вызов waitpid() возвращает идентификатор завершившегося потомка или –1 в случае ошибки. Если указан флаг WNOHANG, а ожидаемый дочерний процесс еще не завершился, то waitpid() возвращает 0.

### pid_t wait3(int \*status, int options, struct rusage \*rusage) и pid_t wait4(pid_t pid, int \*status, int options, struct rusage \*rusage) <a name = "wait_3_4"></a>
Функция wait3 приостанавливает исполнение текущего процесса до того, как дочерний процесс завершит свою работу, или он не получит сигнал, прекращающий его работу, или не будет произведен вызов обработчика прерывания. Если дочерний процесс уже прекратил свою работу на момент вызова этой функции (такой процесс называется "зомби" ("zombie")), то функция немедленно возвращается. Все системные ресурсы, использованные дочерним процессом, будут освобождены. Функция wait4 приостанавливает исполнение текущего процесса до того, как свою работу завершит дочерний процесс с номером pid, или этот процесс не получит сигнал, прекращающий его работу, или не будет произведен вызов обработчика прерывания. Если дочерний процесс pid уже прекратил свою работу на момент вызова этой функции (такой процесс называется "зомби"), то функция немедленно возвращается. Все системные ресурсы, использованные дочерним процессом, будут освобождены.  
Значение параметра pid может быть следующим:  
\< -1 - ожидание любого дочернего процесса, идентификатор группы процессов которого равен абсолютному значению pid.  
-1 - ожидание любого дочернего процесса; это эквивалентно вызову wait3.  
0 - ожидание любого дочернего процесса, идентификатор группы процессов которого равен идентификатору группы процессов текущего процесса.  
\> 0 - ожидание дочернего процесса, идентификатор которого равен pid.  
Идентификатор дочернего процесса, прекратившего свою работу, возвращает -1 при ошибке (в частности, если не существует завершивших свою работу процессов заданного вида) или 0, если был задан флаг WNOHANG, а такого дочернего процесса пока нет.

### void (\*signal(int sig, void (\*func)(int)))(int) <a name = "signal"></a>
Сигнал, который нужно перехватить или игнорировать, задается аргументом sig. Функция, которую следует вызвать при получении заданного сигнала, содержится в аргументе func. Эта функция должна принимать единственный аргумент типа int (принятый сигнал) и иметь тип void. Специальные значения, которые могут быть использованы вместо второго аргумента:  
**SIG_IGN** — игнорировать сигнал;  
**SIG_DFL** — восстановить поведение по умолчанию.

### int kill(pid_t PID, int SIGNAL) <a name = "kill"></a>
Этот системный вызов посылает процессу с идентификатором PID сигнал SIGNAL. Возвращаемое значение: 0 (при успешном завершении) или –1 (в случае ошибки).

### void exit(int code) <a name = "exit"></a>
Функция exit (), завершает работу программы. Аргумент code указывает статус завершения работы. При завершении работы в штатном порядке рекомендуется указывать значение статуса 0 или EXIT_SUCCESS. В противном случае рекомендуется указывать отличное от нуля значение или EXIT_FAILURE. 

### char \*getcwd(char \*BUFFER, size_t SIZE) <a name = "getcwd"></a>
Получение значения текущего каталога. Если в качестве аргумента BUFFER указан NULL, то getcwd() динамически выделяет блок памяти размером SIZE байт и возвращает адрес этого блока, предварительно поместив туда значение текущего каталога. Можно также указать в первом аргументе собственный буфер, а во второй аргумент записать его размер. В этом случае getcwd() поместит в данный буфер значение те- кущего каталога. Если первый аргумент getcwd() равен NULL, то полученный буфер после использования желательно освободить функцией free().

### int chdir(const char \*PATH) <a name = "chdir"></a>
Смена текущего каталога. Системный вызов chdir() изменяет текущий каталог, используя его имя (путь). При успешном завершении функция возвращает 0 и -1, если произошла ошибка.

### int stat(const char \*FNAME, struct stat \*STATISTICS), int fstat (int FD, struct stat \*STATISTICS) и int lstat (const char \*FNAME, struct stat \*STATISTICS) <a name = "stat"></a>
Системный вызов stat() читает информацию о файле с именем FNAME и записывает эту информацию в структуру stat по адресу STATISTICS. Вызов fstat() также читает информацию о файле, который представлен дескриптором FD. И, наконец, lstat() работает аналогично stat(). Но при обнаружении символической ссылки lstat() читает информацию о ней, а не о файле, на который эта ссылка указывает. stat() и lstat() поразному интерпретируют символические ссылки, но ведут себя одинаково по отношению к другим типам файлов. Все системные вызовы семейства stat() возвращают 0 при успешном завершении. В случае ошибки возвращается –1.  
  
struct stat  
{  
   mode_t st_mode;  
   uid_t st_uid;  
   gid_t st_gid;  
   off_t st_size;  
   time_t st_atime;  
   time_t st_mtime;    
};  
  
Перечислим назначение полей структуры stat:
* st_mode — это режим файла;
* st_uid — это числовой идентификатор владельца файла;
* st_gid — идентификатор группы;
* st_size — это размер файла в байтах;
* st_atime — содержит дату и время последнего обращения к файлу;
* st_mtime — содержит дату и время последней модификации файла.
   
### int unlink(const char \*FNAME) <a name = "unlink"></a>
Удаление файла. Аргумент FNAME — это имя удаляемого файла. unlink() возвращает 0 при успешном завершении. В случае ошибки возвращается –1.

### int execve(const char \*PATH, const char \*\*ARGV, const char \*\*ENVP) <a name = "execve"></a>
Загружает в процесс другую программу и передает ей безвозвратное управление. PATH — это путь к исполняемому файлу программы, которая будет запускаться внутри процесса. ARGV — массив аргументов программы, первый аргумент (ARGV[0]) этого массива является именем программы. Последним элементом ARGV должен быть NULL. ENVP —  массив, содержащий окружение запускаемой программы. Этот массив также должен заканчиваться элементом NULL. В случае ошибки execve() возвращает –1, но если новая программа начала выпол- няться, то execve() уже ничего не вернет.

### int dup(int file_descriptor) и int dup2 (int FD1, int FD2) <a name = "dup"></a>
dup() возвращает дубликат файлового дескриптора file_descriptor, в случае ошибки возвращает -1. dup2() копирует файловый дескриптор FD2 в FD1, простыми словами истемный вызов dup2() перенаправляет ввод-вывод с дескриптора FD2 на дескриптор FD1. При успешном завершении dup2() возвращает 0. В случае ошибки возвращается –1.

### int pipe(int PFDS[2]) <a name = "pipe"></a>
При успешном завершении системного вызова pipe() в текущем процессе появля- ется канал, запись в который осуществляется через дескриптор PFDS[0], а чтение — через PFDS[1]. При удачном завершении pipe() возвращает 0. В случае ошибки воз- вращается –1. Закрытие "концов" канала осуществляется при помощи системного вызова close().

### DIR \*opendir(const char \*NAME) <a name = "opendir"></a>
Открывает каталог с именем NAME и возвращает указатель типа DIR. В случае ошибки возвращается NULL.

### struct dirent \*readdir(DIR \*DIRP) <a name = "readdir"></a>
Чтение содержимого каталога. Функция readdir() заносит в поле d_name структуры dirent имя очередного элемента просматриваемого каталога. Если каталог полностью просмотрен, то readdir() возвращает NULL.

### int closedir(DIR \*DIRP) <a name = "closedir"></a>
Функция closedir() закрывает каталог и возвращает 0 при успешном завершении. В случае ошибки closedir() возвращает –1.

### char \*strerror(int ERRN) <a name = "strerror"></a>
Функция возвращает строку — сообщение об ошибке, соответствующее коду ERRN, полученному из errno.

### Переменная extern int errno <a name = "errno"></a>
Для диагностики ошибок всех системных вызовов предусмотрена внешняя переменная errno, если какой-нибудь системный вызов завершился с ошибкой, то код ошибки заносится в errno.

### int isatty(int fd) <a name = "isatty"></a>
Функция isatty() определяет, относится ли файловый дескриптор fd к допустимому устройству терминального типа. Функция isatty() возвращает 1, если fd относится к устройству терминального типа; в противном случае он возвращает 0 и может установить errno, чтобы указать на ошибку.

### char \*ttyname(int fd) <a name = "ttyname"></a>
Функция ttyname() получает имя связанного устройства с файловым дескриптором, для которого isatty() истинно. Функция ttyname() возвращает имя, хранящееся в статическом буфере, которое будет перезаписано при последующих вызовах. Функция ttyname() возвращает имя с завершающим нулем, если устройство найдено и isatty() истинно; в противном случае возвращается NULL-указатель.

### int ttyslot(void) <a name = "ttyslot"></a>
Функция ttyslot() возвращает индекс управляющего терминала текущего процесса в файле. 
