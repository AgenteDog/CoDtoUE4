'''
Setup script.
To install clipboard:
[sudo] python setup.py install
'''
from setuptools import setup, find_packages
import os

def install(appname):

    with open(os.path.join(os.path.dirname(__file__), 'README.rst')) as fobj:
        readme = fobj.read()

    setup(
          name = appname,
          version = "0.0.4",
          description = ''' A cross platform clipboard operation library of Python. Works for Windows, Mac and Linux.''',
          long_description =  readme,
          url = 'https://github.com/terryyin/clipboard',
          download_url='https://pypi.python.org/clipboard/',
          license='MIT',
          platforms='any',
          classifiers = ['Development Status :: 5 - Production/Stable',
                     'Intended Audience :: Developers',
                     'Intended Audience :: End Users/Desktop',
                     'License :: Freeware',
                     'Operating System :: POSIX',
                     'Operating System :: Microsoft :: Windows',
                     'Operating System :: MacOS :: MacOS X',
                     'Topic :: Software Development :: Quality Assurance',
                     'Programming Language :: Python',
                     'Programming Language :: Python :: 2.7',
                     'Programming Language :: Python :: 3.2',
                     'Programming Language :: Python :: 3.3'],
          py_modules = ['clipboard'],
          install_requires=['pyperclip >= 1.3'],
          author = 'Terry Yin',
          author_email = 'terry@odd-e.com',
          )

if __name__ == "__main__":
    import sys
    install('clipboard')
