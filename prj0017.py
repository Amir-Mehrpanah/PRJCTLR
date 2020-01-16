'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''
import requests

sigmal = 0

for i in range(1,1001):
    r = requests.post("https://www.tools4noobs.com/online_tools/number_spell_words/", data={'action': 'ajax_number_spell_words','number':i,'type':0,'locale':'en_GB'})
    print(r.status_code, r.reason)
    if(r.status_code != 200):
        print('Error')
        break
    r = r.content.replace(b'<div class="well">',b'').replace(b'</div>',b'').replace(b' ',b'').replace(b'-',b'')
    
    if(i%100==0 or i < 100):
        sigmal = sigmal+len(r) #without and
    else:
        sigmal = sigmal+len(r)+3

    print(r,sigmal)
print('problem 17 sucks.')