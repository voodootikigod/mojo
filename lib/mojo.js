
// Mojo - Copyright TJ Holowaychuk <tj@vision-media.ca> (MIT Licensed)

;(function(){
	Mojo = {
		
		// --- Version
		
		version: '0.0.1',
		
	 /**
    * Escape HTML.
    *
    * @param  {string} html
    * @return {string}
    * @api public
    */
   
    escape : function(html) {
      return html.toString()
        .replace(/&/gmi, '&amp;')
        .replace(/"/gmi, '&quot;')
        .replace(/>/gmi, '&gt;')
        .replace(/</gmi, '&lt;')
    },

		/**
		 * Enumerate _object_'s _prop_, buffering _fn_'s
		 * return value.
		 *
		 * @param  {object} object
		 * @param  {object} prop
		 * @return {string}
		 * @api private
		 */
		
		enumerate: function(object, prop, fn) {
			if (!prop) return ''
			if (!(prop instanceof Array)) return fn(object)
			for (var buf = [], i = 0, len = prop.length; i < len; ++i)
			  buf.push(fn(prop[i]))
			return buf.join(' ')
		}
	}
})()