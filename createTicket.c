createTicket()
{	
	int randomNumber;//i, k, count, price;
//	char paramName[100];//, s[100];
//  char separators[] = ";";
//  char *token;

    randomNumber = rand()%2;

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	k = 1;
    while (k == 1) {
	    k = choiceCity(randomNumber);    	
    }

	return 0;
}
