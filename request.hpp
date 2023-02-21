#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <curl/curl.h>

using namespace std;

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);

class request {
    private:
        string url;
        CURL *curl_handle;
        CURLcode res;
        string memory;
        string output;
        
    public:
        request(string new_url);
        bool execute();
        string getResult();
        ~request();
};