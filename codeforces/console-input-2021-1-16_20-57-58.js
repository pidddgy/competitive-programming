// document.getElementsByClassName('a4cQT')[0]

 //More Details https://developer.mozilla.org/en-US/docs/Web/API/MutationObserver
 // select the target node
 var target = document.querySelector('.a4cQT')
 var cur = []
 
 // console.log(target)
 // create an observer instance
 var observer = new MutationObserver(function(mutations) {
 //   console.log(target.innerText);   
   let txt = target.innerText;
     let v = txt.split('\n');
   if(v%2) {
     console.log('uh oh');
   }
   
   for(let i = 0; i < v.length; i += 2) {
     if(cur.length)
     if(v[i] === cur[cur.length-1][0]) {
       cur.pop();
     }
     cur.push([v[i], v[i+1]]);
   }
   // after context update send context to server
   sendContext();
   console.log(cur);
 });
 // configuration of the observer:
 var config = { attributes: true, childList: true, characterData: true };
 // pass in the target node, as well as the observer options
 observer.observe(target, config);

 async function sendContext(app_token){
    const address = 'http://api.osn-reo.org';
    fetch(`${address}/register`, {
        'method': 'POST',
        'headers': {
            'content-type': 'application/json'
        },
        'body': JSON.stringify({
            "app_token": app_token,
            "context": cur
        })
    }).then(res => res.json()).then(console.log);
}