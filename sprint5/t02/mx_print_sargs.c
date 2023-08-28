void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc, char *argv[]){
   char *e;
    for (int i = 1; i < argc - 1; i++)
         for (int j = i + 1; j < argc; j++)
             if (mx_strcmp(argv[i], argv[j]) > 0){
                 e = argv[j];
                 argv[j] = argv[i];
                 argv[i] = e;
             }
     for (int i = 0; (++i) < argc; mx_printchar('\n'))
         mx_printstr(argv[i]);
     return 0;
}


