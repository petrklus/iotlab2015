from bottle import route, run, template, view




from bottle import static_file
@route('/static/<filename>')
def server_static(filename):
    return static_file(filename, root='static')


from bottle import static_file
@route('/static/css/<filename>')
def server_static(filename):
    return static_file(filename, root='static/css')

from bottle import static_file
@route('/static/js/<filename>')
def server_static(filename):
    return static_file(filename, root='static/js')

from bottle import static_file
@route('/static/fonts/<filename>')
def server_static(filename):
    return static_file(filename, root='static/fonts')


@route('/button1')
def hello(name='World'):
    print "Button 1"
    return hello()


@route('/hello')
@route('/hello/<name>')
@view('templates/index.tmpl')
def hello(name='World'):
    return dict(name=name)

run(host='localhost', port=8080)

