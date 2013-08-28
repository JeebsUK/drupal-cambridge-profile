api = 2
core = 7.x

includes[cambridge_lite] = "cambridge_lite.make"

; contrib

projects[admin_menu] = "3.0-rc4"
projects[advanced_help] = "1.0"
projects[context] = "3.0-beta7"
projects[ckeditor] = "1.13"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.2/ckeditor_4.2_full.tar.gz"
libraries[ckeditor][destination] = "modules/ckeditor"
projects[date] = "2.6"
projects[delta] = "3.0-beta11"
projects[easy_breadcrumb] = "2.7"
projects[fancybox] = "2.0-beta2"
projects[fancybox][patch][] = "https://gist.github.com/anonymous/6365115/raw/27aa33685c0f484b6e1b9f63d61e98d73af9775b/fancybox_jquery.patch"
libraries[fancybox][download][type] = "file"
libraries[fancybox][download][url] = "https://github.com/fancyapps/fancyBox/archive/v2.1.5.tar.gz"
projects[globalredirect] = "1.5"
projects[google_analytics] = "1.3"
projects[imagecrop][version] = "1.0-rc3"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6241365/raw/fccdba35efbd5ec106d8b92a8af98f71172e1870/imagecrop_query_string.patch"
projects[imagecrop][patch][] = "https://gist.github.com/thewilkybarkid/6351355/raw/a34c91e4480aa7c4c0b79644e13aeeec914c1726/imagecrop_theme.patch"
projects[media] = "1.3"
projects[nodequeue] = "2.0-beta1"
projects[pathologic] = "2.11"
projects[realname] = "1.1"
projects[redirect] = "1.0-rc1"
projects[transliteration] = "3.1"
projects[webform] = "3.19"
projects[workbench] = "1.2"
projects[workbench_access] = "1.2"
projects[workbench_media] = "1.1"
projects[workbench_moderation] = "1.3"
