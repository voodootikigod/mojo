
// Mojo - Copyright TJ Holowaychuk <tj@vision-media.ca> (MIT Licensed)

;(function(){
	Mojo = {
		version: '0.0.1',
		enumerate: function(a, fn) {
			for (var buf = [], i = 0, len = a.length; i < len; ++i)
			  buf.push(fn(a[i]))
			return buf.join(' ')
		}
	}
})()