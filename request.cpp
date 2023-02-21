#include "request.hpp"

// A function to manage memory
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) { //change first void to char
         ((string*)userp)->append((char*)contents, size * nmemb);
         return size * nmemb;
}

// Constructs the request class
request::request(string new_url) {
   url = new_url;
}

// Executes the api call
bool request::execute(){
   // Initialize curl
   curl_global_init(CURL_GLOBAL_ALL);
   curl_handle = curl_easy_init();

   // Making the api calls
   curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());
   curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
   curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &memory);
   curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

   res = curl_easy_perform(curl_handle);
   output = memory;

   if(res != CURLE_OK) {
      return true;
   } else {
      return false;
   }

}

// Returns the result of the api call
string request::getResult(){
   return output;
}

request::~request(){
   curl_easy_cleanup(curl_handle);
   curl_global_cleanup();
}
