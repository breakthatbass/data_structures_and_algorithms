from setuptools import setup, find_packages
from notes.__init__ import __version__, __author__

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name='notes',
    version=f'{__version__}',
    description='cheatsheet for the commands I often forget',
    long_description=long_description,
    long_description_content_type='text/markdown',
    author=f'{__author__}',
    author_email='gamache.taylor@gmail.com',
    url='https://github.com/breakthatbass/scripts/notes-py',
    packages=find_packages(),
    license='MIT',
    install_requires=['termcolor'],
    entry_points={
        'console_scripts' : ['notes = notes.notes:main']
   }
)