import csv
import requests
from bs4 import BeautifulSoup as bs
from selenium import webdriver
import time

def toDoNewsCrawling(url_list, news_title_list, news_text_list):
    soup_list = []
    for i in range(len(url_list)):
        response = requests.get(url_list[i])
        html_text = response.text
        soup_list.append(bs(html_text, 'html.parser'))
        news_title_list.append(soup_list[i].select_one('h2.media_end_head_headline').get_text())
        news_text_list.append(soup_list[i].select_one('div#dic_area.go_trans._article_content').get_text())

def toDoCommentCrawling(url_list, comment_list):
    for i in range(len(url_list)):
        driver = webdriver.Chrome('./chromedriver.exe')
        driver.implicitly_wait(20)
        driver.get(url_list[i])   
        
        while True:
            try:
                if url_list[i][len(url_list[i])-3:len(url_list[i])] == '100':
                    cosm = driver.find_element_by_css_selector('div.simplecmt_link_text')
                    cosm.click()
                else:
                    btn = driver.find_element_by_css_selector('span.u_cbox_in_view_comment')
                    btn.click()
            except:
                break
        
        #네이버 클린봇 옵션 해제
        cleanbot = driver.find_element_by_css_selector('a.u_cbox_cleanbot_setbutton')
        cleanbot.click()
    
        time.sleep(1)
        cleanbot_disable = driver.find_element_by_xpath("//input[@id='cleanbot_dialog_checkbox_cbox_module']")
        cleanbot_disable.click()
        time.sleep(1)
        cleanbot_confirm = driver.find_element_by_css_selector('button.u_cbox_layer_cleanbot2_extrabtn')
        cleanbot_confirm.click()
        time.sleep(1)
        
        #더보기 계속 클릭하기
        while True:
            try:
                btn_more = driver.find_element_by_css_selector('span.u_cbox_page_more')
                btn_more.click()
                time.sleep(1)
            except:
                break
                
        #댓글 크롤링
        comments = driver.find_elements_by_css_selector('span.u_cbox_contents')
    
        for j in range(len(comments)):
            comments[j] = comments[j].text
        comment_list.append(comments)
        
def writeCsvFile(file_path, news_title_list, news_text_list):
    media_dic = {'056' : 'KBS', '055' : 'SBS', '214' : 'MBC', '437' : 'JTBC', '023' : '조선일보', '001' : '연합뉴스', '028' : '한겨레'}
    event_dic = {'100' : '정치', '101' : '경제', '102' : '사회', '103' : '생활/문화', '104' : '세계'}
    
    csv_file = open(file_path, 'w', newline='', encoding='utf-8-sig')
    new_csv_file = csv.writer(csv_file)
    for i in range(len(news_title_list)):
        new_csv_file.writerow([news_title_list[i], news_text_list[i], comment_list[i], media_dic[url_list[i][39:42]], event_dic[url_list[i][58:61]]])
    csv_file.close()


# 크롤링할 뉴스 url
url_list = [
           'https://n.news.naver.com/mnews/article/055/0000970150?sid=100', 
           'https://n.news.naver.com/mnews/article/214/0001193646?sid=100', 
           'https://n.news.naver.com/mnews/article/437/0000297345?sid=101', 
           'https://n.news.naver.com/mnews/article/023/0003688388?sid=101', 
           'https://n.news.naver.com/mnews/article/214/0001193561?sid=102', 
           'https://n.news.naver.com/mnews/article/056/0011258055?sid=102', 
           'https://n.news.naver.com/mnews/article/023/0003688489?sid=103', 
           'https://n.news.naver.com/mnews/article/001/0013147594?sid=103', 
           'https://n.news.naver.com/mnews/article/028/0002588772?sid=104', 
           'https://n.news.naver.com/mnews/article/023/0003688429?sid=104'
           ]

# url의 정보
news_title_list = []
news_text_list = []
soup_list = []
comment_list=[]
csv_file_path = 'test_csv.csv'
toDoNewsCrawling(url_list, news_title_list, news_text_list)
toDoCommentCrawling(url_list, comment_list)
writeCsvFile(csv_file_path, news_title_list, news_text_list)

