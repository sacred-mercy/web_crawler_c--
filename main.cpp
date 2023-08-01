#include "webCrawlerMain.cpp"

int main()
{
    // Create a web crawler object
    WebCrawler *webCrawler = WebCrawler::getWebCrawler();

    // Start the web crawler
    webCrawler->start("https://sacred-mercy.github.io/personal-website/", 1, 1);

    return 0;
}