from selenium import webdriver
from selenium.webdriver.common.keys import Keys

driver = webdriver.Firefox()
driver.get("http://www.flashscore.com/basketball/germany/bbl-2014-2015/results/")

preloader_name = "Show more matches"
preloads_number = 0




try:
    for i in range(10):
        preloader = driver.find_element_by_link_text(preloader_name)
        preloader.send_keys(Keys.RETURN)
        preloads_number += 1
except Exception:
    print("Resulted number of preloads %d" % preloads_number)
driver.execute_script("window.scrollBy(0,22250)", "");
