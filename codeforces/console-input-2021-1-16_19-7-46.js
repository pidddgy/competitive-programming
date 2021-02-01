// document.getElementsByClassName('a4cQT')[0]

 //More Details https://developer.mozilla.org/en-US/docs/Web/API/MutationObserver
 // select the target node
var target = document.querySelector('.a4cQT')
var cur = []

// console.log(target)
// create an observer instance
var observer = new MutationObserver(function(mutations) {
//   console.log(target.innerText);   
  
});
// configuration of the observer:
var config = { attributes: true, childList: true, characterData: true };
// pass in the target node, as well as the observer options
observer.observe(target, config);