<?hh

require_once(__DIR__ . "/../vendor/autoload.php");

if ($argc != 2) {
  echo "Usage: hhvm project.hh <hacklang file>";
  return;
}

require_once($argv[1]);
