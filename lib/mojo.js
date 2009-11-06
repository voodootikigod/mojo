
// Mojo - Copyright TJ Holowaychuk <tj@vision-media.ca> (MIT Licensed)

;(function(){
	Mojo = {
		version: '0.0.1',
		enumerate: function(object, prop, fn) {
			if (!prop) return ''
			if (!(prop instanceof Array)) return fn(object)
			for (var buf = [], i = 0, len = prop.length; i < len; ++i)
			  buf.push(fn(prop[i]))
			return buf.join(' ')
		}
	}
})()