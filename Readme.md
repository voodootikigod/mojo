
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

    $ mojo < in > out
    $ mojo --help

## Running Tests

    $ make test
    
## Example

View ./examples to see the source for the
examples shown below.

examples/template.html

    <html>
      <head>
        <title>{title}</title>
      </head>
      <body>
        <h1>{title}</h1>
        {#articles}
          <div class="article">
            <h2>{title}</h2>
            <p>{body}</p>
            {#published}
              <p>{title} is published</p>
            {/published}
          </div>
        {/articles}
      </body>
    </html>
    
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

    <html>
      <head>
        <title>Articles</title>
      </head>
      <body>
        <h1>Articles</h1>

          <div class="article">
            <h2>One</h2>
            <p>some more one</p>

          </div>

          <div class="article">
            <h2>Two</h2>
            <p>some more two</p>

              <p>Two is published</p>

          </div>

      </body>
    </html>
    
## License 

(The MIT License)

Copyright (c) 2008 - 2009 TJ Holowaychuk <tj@vision-media.ca>

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