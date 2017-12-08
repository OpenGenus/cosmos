from setuptools import setup, find_packages
# To use a consistent encoding
from codecs import open
from os import path

here = path.abspath(path.dirname(__file__))

# Get the long description from the README file
with open(path.join(here, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()


setup(

	name='B.E.N.J.I',
	version='1.0',
	description='Your Voice Assistant',


	author:'Dhruv Apte',
	author_git="https://github.com/the-ethan-hunt/",
	author_website="https://the-ethan-hunt.github.io/",
	author_email='dhruvgirishapte@gmail.com',
	project_url='https://github.com/the-ethan-hunt/B.E.N.J.I./',

	license='The MIT License 2017',


	classifiers=[
       
        'Development Status :: 3 - Alpha',

        # Indicate who your project is intended for
        'Intended Audience :: Developers and Users who want a voice Assistant',
        'Topic :: Software Development :: Build Tools',

        # Pick your license as you wish (should match "license" above)
        'License :: OSI Approved :: MIT License',

        # Specify the Python versions you support here. In particular, ensure
        # that you indicate whether you support Python 2, Python 3 or both.
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.3',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
    ],
	package=[""],
	install_requires=[
	'beautifulsoup4','certifi','chardet','client','colorama','dataecorator','funcsigs',
	'future','idnapython','ipython-genutils','jedi','latex','mpmath','numpy','pandas',
	'parso','pickleshare','prompt-toolkit5','PyAudio1',
	'Pygments','pypiwin32ython-dateutil','pytz3','requests4','shutilwhich',
	'simplegeneric','six0','SpeechRecognition','sympy','tempdir','traitlets','urllib','wikipedia'
	],
	package_data={},
	data_file=[],
	dependency_links=['']

	entry_points={
        'console_scripts': [
            'sample=sample:benji',
        ],
    },
)
