/**
	Http interface symplifies and encapsulates Http interactions on top of 
	Comms simple&crossplatorm c network library

*/
#include "comms.h"

#ifdef _WIN32
  #define HTTP_API __declspec(dllexport)
#else
  #define HTTP_API
#endif

typedef struct IO_S * IO;

typedef struct Req_S * Req;

typedef struct Resp_S * Resp;

typedef struct Map_S * Map;

// httpRequest creates a new Http Request with a given method and URL
// On error a NULL Request is returned and err Error's message is set
HTTP_API Req httpRequest(char* method, char* url, Error err);

// reqError returns the latest Request Error
// use onError(reqError(req)) to test for Request errors
HTTP_API Error* reqError(Req req);

// reqFormPars returns the map of Request Form Parameters (it NEVER fails)
HTTP_API Map reqFormPars(Req req);

// reqHeaders returns the request Headers (it NEVER fails)
HTTP_API Map reqHeaders(Req req);

// reqBodyContent sets the body contents to be that of body
// If called more than once or mixed with reqBodyFrom, the last call Wins
// On error Req's Error is set
HTTP_API void reqBodyContent(Req req, const char* body);

// reqBodyFrom sets the body contents to be that of bodyIO
// If called more than once or mixed with reqBodyContent, the last call Wins
// On error Req's Error is set
HTTP_API void reqBodyFrom(Req req, IO bodyIO);

// reqSend send the Http requests
// Returns and HTTP Response or NULL and Req's Error set to a proper value 
HTTP_API Resp reqSend(Req req);

// mapNew returns a new empty Map or NULL and Error is set
HTTP_API Map mapNew(Error error);

// mapError returns the latest Map Error
// use onError(mapError(req)) to test for IO errors
HTTP_API Error* mapError(Map m);

// mapAdd replaces or adds a name-value pair
// On error Map's Error is set
HTTP_API void mapAdd(Map m, char* name, void* value);

// mapGet returns the value of the given name
// On error Map's Error is set
HTTP_API void* mapGet(Map m, char* name);

// mapRemove deletes and returns the value of the given name
// On error Map's Error is set
HTTP_API void* mapRemove(Map m, char* name);

// respError returns the latest Request Error
// use onError(reqError(req)) to test for Request errors
HTTP_API Error* reqError(Req req);

// respError returns the latest Response Error
// use onError(respError(resp)) to test for Request errors
HTTP_API Error* respError(Resp resp);

// respStatus returns the HTTP response status code
// On error Resp's Error is set
HTTP_API int respStatus(Resp resp);

// respHeaders returns the response Headers (it NEVER fails)
HTTP_API Map respHeaders(Resp resp);

// respBody reads and returns the whole response body in full
// Do not call it when the response can be too big for memory (like with some files)
// use respBodyTo on those cases
// On error Resp's Error is set
HTTP_API char* respBody(Resp resp);

// respBodyTo reads the whole response body writing it to io
// Useful when the response can be too big for memory (like with some files)
// On error Resp's Error is set
HTTP_API void respBodyTo(Resp resp, IO io);

