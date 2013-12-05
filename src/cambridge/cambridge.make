api = 2
core = 7.x

includes[cambridge_base] = "../cambridge_base.make"

; contrib

projects[admin_menu] = "3.0-rc4"
projects[advanced_help] = "1.0"
projects[ckeditor] = "1.13"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.2/ckeditor_4.2_full.tar.gz"
projects[context] = "3.1"
projects[date] = "2.6"
projects[delta] = "3.0-beta11"
projects[easy_breadcrumb] = "2.9"
projects[email] = "1.2"
projects[entity] = "1.2"
projects[entityreference] = "1.0"
projects[expire] = "1.0-beta1"
projects[fancybox][version] = "2.0-beta2"
projects[fancybox][subdir] = "patched"
projects[fancybox][patch][] = "https://gist.github.com/thewilkybarkid/6550012/raw/27aa33685c0f484b6e1b9f63d61e98d73af9775b/fancybox_jquery.patch"
libraries[fancybox][download][type] = "file"
libraries[fancybox][download][url] = "https://github.com/fancyapps/fancyBox/archive/v2.1.5.tar.gz"
projects[feeds] = "2.0-alpha8"
projects[field_collection][version] = "1.0-beta5"
projects[field_collection][subdir] = "patched"
projects[field_collection][patch][] = "http://drupal.org/files/field_collection_with_workbench_moderation-1807460-1.patch"
projects[field_collection][patch][] = "http://drupal.org/files/field_collection-default-revision-with-workbench-moderation-1901892-19.patch"
projects[field_group] = "1.3"
projects[globalredirect] = "1.5"
projects[google_analytics] = "1.4"
projects[job_scheduler] = "2.0-alpha3"
projects[media] = "1.3"
projects[memcache][version] = "1.0"
projects[memcache][subdir] = "patched"
projects[memcache][patch][] = "http://drupal.org/files/memcache-missing-extension-1470324-7.patch"
projects[memcache][patch][] = "http://drupal.org/files/memcache-display-connection-error-1830496-6.patch"
projects[menu_admin_per_menu] = "1.0"
projects[menu_force] = "1.2"
projects[nodequeue] = "2.0-beta1"
projects[pathologic] = "2.11"
projects[realname] = "1.1"
projects[redirect][version] = "1.0-rc1"
projects[redirect][subdir] = "patched"
projects[redirect][patch][] = "http://drupal.org/files/redirect-prevent_circular_redirects-1817976-42.patch"
projects[rules] = "2.6"
projects[transliteration] = "3.1"
projects[varnish][version] = "1.0-beta2"
projects[varnish][subdir] = "patched"
projects[varnish][patch][] = "https://gist.github.com/thewilkybarkid/6595645/raw/e53554206350c1b00316fcf02f2ff61c0bdfee36/varnish_watchdog_success.patch"
projects[varnish][patch][] = "https://gist.github.com/thewilkybarkid/6595676/raw/4ddb6a03ce521ab5520e27099997650a2e390679/varnish_authentication_fix.patch"
projects[varnish][patch][] = "https://gist.github.com/thewilkybarkid/6595681/raw/be6e7a25f20745d875d28030f6f4b10b82735089/varnish_site_alias.patch"
projects[webform] = "3.19"
projects[workbench] = "1.2"
projects[workbench_access] = "1.2"
projects[workbench_media] = "1.1"
projects[workbench_moderation] = "1.3"

; features

projects[cambridge_questions_and_answers][type] = "module"
projects[cambridge_questions_and_answers][download][type] = "file"
projects[cambridge_questions_and_answers][download][url] = "https://github.com/misd-service-development/drupal-feature-questions-and-answers/archive/master.tar.gz"
projects[cambridge_questions_and_answers][subdir] = "features"
