
# Mojo

  Mustache template compiler for ultra-fast native language templates.
  
## Supported languages

  * JavaScript
  
## Dependencies

  * gcc (compiler)
  * leg (parser generator)
  * jspec (test suite only)
  
## Building From Source

    $ make
    $ make install
    
## Mojo Binary

    $ mojo &lt; in &gt; out
    $ mojo --help

## Running Tests

    $ make test
    
## Example

examples/template.html

    &lt;html&gt;
      &lt;head&gt;
        &lt;title&gt;{title}&lt;/title&gt;
      &lt;/head&gt;
      &lt;body&gt;
        &lt;h1&gt;{title}&lt;/h1&gt;
        {#articles}
          &lt;div class="article"&gt;
            &lt;h2&gt;{title}&lt;/h2&gt;
            &lt;p&gt;{body}&lt;/p&gt;
            {#published}
              &lt;p&gt;{title} is published&lt;/p&gt;
            {/published}
          &lt;/div&gt;
        {/articles}
      &lt;/body&gt;
    &lt;/html&gt;
    
example template rendering implementation:

    load('lib/mojo.js')
    
    function render(template, o) {
    	return eval(readFile('examples/' + template + '.html.js'))
    }
    
template object:

    page = {
    	title: 'Articles',
    	articles: [
    	  { title: 'One', body: 'some more one' },
    	  { title: 'Two', body: 'some more two', published: true }
    	]
    }

    print(render('template', page))
    
rendered markup output:

    &lt;html&gt;
      &lt;head&gt;
        &lt;title&gt;Articles&lt;/title&gt;
      &lt;/head&gt;
      &lt;body&gt;
        &lt;h1&gt;Articles&lt;/h1&gt;

          &lt;div class="article"&gt;
            &lt;h2&gt;One&lt;/h2&gt;
            &lt;p&gt;some more one&lt;/p&gt;

          &lt;/div&gt;

          &lt;div class="article"&gt;
            &lt;h2&gt;Two&lt;/h2&gt;
            &lt;p&gt;some more two&lt;/p&gt;

              &lt;p&gt;Two is published&lt;/p&gt;

          &lt;/div&gt;

      &lt;/body&gt;
    &lt;/html&gt;
    
## License 

(The MIT License)

Copyright (c) 2008 - 2009 TJ Holowaychuk &lt;tj@vision-media.ca&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.