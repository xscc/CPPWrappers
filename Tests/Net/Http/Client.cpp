/**
 *
 *       @file  Client.cpp
 *
 *      @brief  test client
 *
 *    @version  1.0
 *       @date  10/10/2011 19:22:33
 *
 *     @author  Ben D. (BD), dbapps2@gmail.com
 *
 */

#include <Net/HttpProtocol.h>
#include <Net/HtmlParser.h>

int main()
{
    Host h("checkip.dyndns.org", 80);
    HttpProtocol proto(h);
    HttpRequest req("/", HttpRequest::Head);
    req.setField(HttpTypes::UserAgent, "Mozilla");
    req.setField(HttpTypes::From, "Ben D");
    req.setBody("<html> hello world </html>");
    req.checkAndFix();
    cout << "Request " << endl << req.toString() << endl;
    proto.sendRequest(req);
    HttpResponse r = proto.getResponse();
    r.parse();
    cout << r.toString() << endl;
    cout << "http version [" << r.getHttpVersion() << "]" << endl;
    cout << "Content length[" << r.getContentLength() << "]" << endl;
    cout << "Code [" << r.getResponseCode() << "]" << endl;
    cout << "Body [" << r.getBody() << "]" << endl;
    cout << "Server [" << r.getField("Server") << "]" << endl;
	string s = "    <html> this is is html           <body> hello wolrd </body><body2> byte byte </body2> </html>";
	HtmlParser parser(r.getBody());
	cout<<"Parser result " <<parser.parse()<<endl;
	HtmlElement root = parser.getElem();

	cout<<"Data " <<root["html"]["body"].getContents()<<endl;
	root["html"]["body"] = "this is another ip";
	cout<<"Data " <<root["html"]["body"].getContents()<<endl;
	root["html"]["tail"] = "hello 321";
	cout<<"Data " <<root["html"]["tail"].getContents()<<endl;


}
