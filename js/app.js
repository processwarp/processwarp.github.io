(function($) {
$(function() {

var target = document.getElementById('menu');
var $hammer = new Hammer(target);

$hammer.get('tap').set({
  enable: true
});

$hammer.on('tap', function() {
  $('#menu-list').add('.dim').toggleClass('active');
  $('#menu > div').toggleClass('sp-hide');
});

});
})(jQuery);
