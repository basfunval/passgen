static char* LOWER = "abcdefghijklmnopqrstuvwxyz";
static char* UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char* LETTER = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char* NUMBER = "1234567890";
static char* SYMBOL = "!\"#$%&\'()*()+,-./:;<=>?@[\\]^_`{|}~";
static char* ASCII = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&\'()*()+,-./:;<=>?@[\\]^_`{|}~1234567890";
static char* HELP_TEXT = "Usage: passgen [OPTION]...\nGenerate random passwords\n\nOptions:\n  -l (LENGTH)    length of password\n  -c (CHARSET)   charset for password [lower|upper|letter|alphanum|number|symbol]\n  -C (STRING)    string to use as explicit charset for password\n";