#! /bin/sh

if [ "x${1}" = 'x-h' -o "x${1}" = '--help' -o "x${1}" = 'x' ]
then
	echo "Usage: ${0} [XQF's source root directory]"
	exit
fi

flag_pack_url='http://www.famfamfam.com/lab/icons/flags/famfamfam_flag_icons.zip'

xqf_repo="${1}"
temp_dir="$(mktemp -d /tmp/import-flags.XXXXXXXX)"

xqf_flags_path="${xqf_repo}/pixmaps/flags/country"
mkdir -p "${xqf_flags_path}"

curl "${flag_pack_url}" > "${temp_dir}/flags.zip"
(cd "${temp_dir}"; unzip 'flags.zip')

(cd "${temp_dir}/png"; ls ??.png) | while read name
do
	cp -v "${temp_dir}/png/${name}" "${xqf_flags_path}/${name}"
done

#EOF
