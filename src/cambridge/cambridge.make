api = 2
core = 7.x

includes[cambridge_base] = "../cambridge_base.make"

; contrib

projects[admin_menu] = "3.0-rc5"
projects[advanced_help] = "1.1"
projects[auto_entitylabel] = "1.3"
projects[block_titlelink] = "1.3"
projects[ckeditor] = "1.16"
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.7/ckeditor_4.4.7_full.tar.gz"
projects[ckeditor_link] = "2.3"
projects[context] = "3.6"
projects[crazyegg] = "1.0"
projects[date] = "2.8"
projects[delta] = "3.0-beta11"
projects[diff] = "3.2"
projects[easy_breadcrumb] = "2.12"
projects[email] = "1.3"
projects[entity] = "1.6"
projects[entityreference] = "1.1"
projects[environment_indicator][version] = "2.5"
projects[environment_indicator][patch][] = "http://www.drupal.org/files/issues/z-index-2331315-1.patch"
projects[expire] = "1.0-beta1"
projects[facetapi] = "1.5"
projects[fancybox][version] = "2.0-beta5"
projects[fancybox][patch][] = "https://gist.githubusercontent.com/thewilkybarkid/6550012/raw/2f8e8a4cc736cf550c6ce2f41ed4ef9dc7efcd05/fancybox_jquery.patch"
libraries[fancybox][download][type] = "file"
libraries[fancybox][download][url] = "https://github.com/fancyapps/fancyBox/archive/v2.1.5.tar.gz"
projects[features_extra] = "1.0-beta1"
projects[feeds][version] = "2.0-alpha8"
projects[feeds][patch][] = "http://cgit.drupalcode.org/feeds/patch/?id=004f03c"
projects[feeds][patch][] = "http://cgit.drupalcode.org/feeds/patch/?id=f22a0f7"
projects[feeds][patch][] = "http://cgit.drupalcode.org/feeds/patch/?id=7b36762"
projects[feeds_tamper] = "1.0"
projects[feeds_xpathparser] = "1.0"
projects[field_collection] = "1.0-beta8"
projects[field_group] = "1.4"
projects[field_permissions] = "1.0-beta2"
projects[field_validation]= "2.4"
projects[filefield_sources] = "1.9"
projects[globalredirect] = "1.5"
projects[google_analytics] = "1.4"
projects[imageapi_optimize] = "1.2"
projects[job_scheduler] = "2.0-alpha3"
projects[linkchecker] = "1.2"
projects[markup] = "1.1-beta1"
projects[media] = "1.4"
projects[media_flickr] = "1.0-alpha4"
projects[media_soundcloud] = "1.0"
projects[media_vimeo] = "1.0-beta5"
projects[media_youtube] = "1.0-beta3"
projects[memcache] = "1.5"
projects[menu_admin_per_menu] = "1.0"
projects[menu_force] = "1.2"
projects[menu_trail_by_path] = "2.0"
projects[menu_view_unpublished] = "1.0-beta3"
projects[metatag] = "1.4"
projects[module_filter] = "2.0"
projects[nodequeue] = "2.0-beta1"
projects[pathologic] = "2.12"
projects[persistent_menu_items] = "1.0"
projects[publishcontent] = "1.3"
projects[realname] = "1.2"
projects[redirect][version] = "1.0-rc1"
projects[redirect][patch][] = "http://drupal.org/files/redirect-prevent_circular_redirects-1817976-42.patch"
projects[restws] = "2.3"
projects[rules] = "2.9"
projects[scheduler] = "1.3"
projects[search_api] = "1.14"
projects[search_api_db] = "1.4"
projects[select_or_other] = "2.20"
projects[sharethis] = "2.10"
projects[similarterms] = "2.3"
projects[smart_trim][version] = "1.4"
projects[smart_trim][patch][] = "http://drupal.org/files/issues/smart_trim_remove_punctuation_from_end_of_truncated_output-2169583-3.patch"
projects[strongarm] = "2.0"
projects[synonyms] = "1.2"
projects[tac_lite] = "1.2"
projects[term_merge] = "1.2"
projects[transliteration] = "3.2"
projects[twitter_block] = "2.2"
projects[uuid] = "1.0-alpha6"
projects[varnish][version] = "1.0-beta2"
projects[varnish][patch][] = "https://gist.github.com/thewilkybarkid/6595645/raw/e53554206350c1b00316fcf02f2ff61c0bdfee36/varnish_watchdog_success.patch"
projects[varnish][patch][] = "https://gist.github.com/thewilkybarkid/6595676/raw/4ddb6a03ce521ab5520e27099997650a2e390679/varnish_authentication_fix.patch"
projects[varnish][patch][] = "http://cgit.drupalcode.org/varnish/patch/?id=d4cddfed72855199be9dd0047f5d80183c723ac0"
projects[varnish][patch][] = "http://www.drupal.org/files/issues/purge-site-aliases-2185281-1.patch"
projects[varnish][patch][] = "http://www.drupal.org/files/issues/varnish-2371907-24.patch"
projects[view_unpublished] = "1.2"
projects[views_accordion] = "1.1"
projects[views_bulk_operations] = "3.2"
projects[views_data_export] = "3.0-beta8"
projects[views_rss] = "2.0-rc4"
projects[webform] = "3.22"
projects[webform_conditional] = "1.0-beta2"
projects[workbench] = "1.2"
projects[workbench_access] = "1.2"
projects[workbench_media] = "1.1"
projects[workbench_moderation] = "1.4"

; features

projects[body_field_definition][version] = "1.0"
projects[body_field_definition][patch][] = "http://www.drupal.org/files/issues/foreign-keys-2454593-1.patch"
projects[body_field_definition][subdir] = "features"

projects[cambridge_news][type] = "module"
projects[cambridge_news][download][type] = "file"
projects[cambridge_news][download][url] = "https://github.com/misd-service-development/drupal-feature-news/archive/7.x-2.1.tar.gz"
projects[cambridge_news][patch][] = "https://github.com/thewilkybarkid/drupal-feature-news/commit/a5e2418c3a31420b123c845183189589e58a2954.patch"
projects[cambridge_news][subdir] = "features"

projects[cambridge_related_links][type] = "module"
projects[cambridge_related_links][download][type] = "file"
projects[cambridge_related_links][download][url] = "https://github.com/misd-service-development/drupal-feature-related-links/archive/7.x-1.1.tar.gz"
projects[cambridge_related_links][subdir] = "features"

projects[cambridge_questions_and_answers][type] = "module"
projects[cambridge_questions_and_answers][download][type] = "file"
projects[cambridge_questions_and_answers][download][url] = "https://github.com/misd-service-development/drupal-feature-questions-and-answers/archive/7.x-1.2.tar.gz"
projects[cambridge_questions_and_answers][subdir] = "features"
