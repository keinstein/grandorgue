# GrandOrgue - free pipe organ simulator
# 
# Copyright 2006 Milan Digital Audio LLC
# Copyright 2009-2015 GrandOrgue contributors (see AUTHORS)
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of the
# License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

function(add_cxx_option _option)
  set(_name "OPTION_LINK_${_option}")
  string(REGEX REPLACE "=" "-EQ" _name ${_name})
  string(REGEX REPLACE "\\+" "-P" _name ${_name})
  SET(CMAKE_REQUIRED_FLAGS "${_option}")
  CHECK_CXX_COMPILER_FLAG("" ${_name})
  if(${_name})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${_option}" PARENT_SCOPE)
  endif()
endfunction()
