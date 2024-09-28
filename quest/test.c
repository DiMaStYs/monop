#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <locale.h>

#define strsize(args...) snprintf(NULL, 0, args)+sizeof('\0')

char * handle_request(int *request_return){
	char *response;//
	char *html_not_found = "<html><body><h1>Not found</h1></body></html>";
    
	response=malloc(strsize("HTTP/1.1 404 OK\n"
				"Content-Type:text/html;charset=utf-8\n\%s",
				html_not_found));
	if(response == NULL){
		*request_return = -1;
		return NULL;
	}
	sprintf(response, "HTTP/1.1 404 OK\nContent-Type:text/html;charset=utf-8\n\%s",
			html_not_found);
	*request_return = 0;

	return response;
    

}
char * error_send(){
	char *c="";
	return c;
}
void error_handler(char * buffer, char *buffer2, int k,int err){
	puts("Hello");
}
	
	
char * m(size_t * request_return, int err){
		char buffer[5];
		
		
		
		char * response = error_send();
		if(response == NULL){
			*request_return = -10;
			return NULL;
		}
        *request_return = -1;
        error_handler(buffer, "error_buffer.txt", 0, err);
        return response; 
}
int main(){
	setlocale(LC_ALL, "");
	char *buffer;
	
	if((buffer = getcwd(NULL,0))==NULL){
		perror("_getcwd error");
	}else{
		printf("%s \nLength: %zu\n", buffer, strlen(buffer));
		free(buffer);
	}
	return 0;
}
