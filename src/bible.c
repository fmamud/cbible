#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "v0.1"

#define BASE_URL "https://bible-api.com"

void helpMsg(char *msg) {
    printf("%s", msg);
    exit(1);
}

void help() {
    helpMsg("Usage: bible <book> [<chapter>[:<verse>]]");
}

int main (int argc, char const *argv[]) {
    char predicate[20], url[60];
    
    if (argc <= 1) help();
    else if ((strcmp(argv[1], "-v") & strcmp(argv[1], "-version")) == 0) helpMsg(VERSION);
    else if (argc == 2) strcat(predicate, argv[1]);
    else if (argc == 3) sprintf(predicate, "%s+%s", argv[1], argv[2]);
    else if (argc == 4) sprintf(predicate, "%s+%s:%s", argv[1], argv[2], argv[3]);
    
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    
    if (curl) {
        sprintf(url, "%s/%s", BASE_URL, predicate);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }
    
    curl_easy_cleanup(curl);
    
    return 0;
}