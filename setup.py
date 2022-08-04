import glob
import os.path as osp

from setuptools import Extension, find_packages, setup
from setuptools.command.build_ext import build_ext
from torch.utils.cpp_extension import CppExtension, CUDAExtension

from pybind11.setup_helpers import Pybind11Extension


def get_extensions():
    extensions = []
    for file in ['add_example', 'pet_example']:
        extension = Pybind11Extension(
            name=osp.join('src', file),
            sources=glob.glob('src/add_example/*.cpp'),
        )
        extensions.append(extension)
    return extensions


setup(
    name='cpython_learn',
    packages=['src'],
    ext_modules=get_extensions(),
    cmdclass={"build_ext": build_ext}
)
